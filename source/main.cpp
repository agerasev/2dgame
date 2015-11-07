#include <media/media.hpp>
#include <graphics/graphics.hpp>

#include "graphics.hpp"

class GraphicsHandler : public media::Graphics::Handler {
private:
	gfx::Context *context;
	// Graphics graphics;
	
	class GFXHandler : public gfx::Handler {
	public:
		gfx::Ring *ring;
		virtual void init() override {
			ring = new gfx::Ring();
			ring->setInnerRadius(0.8);
			ring->setColor(gfx::YELLOW & gfx::ALPHA(0.5));
			ring->transform(fmat2(100,0,0,100));
		}
		virtual void dispose() override {
			delete ring;
		}
		virtual void draw(double dt) override {
			super->clear();
			super->drawShape(ring);
		}
	} gfx_handler;

public:
	GraphicsHandler() = default;
	virtual ~GraphicsHandler() = default;
	
	virtual void create() override {
		logMessage("graphics created");
		context = new gfx::Context(&gfx_handler);
	}
	
	virtual void destroy() override {
		logMessage("graphics destroyed");
		delete context;
	}
	
	virtual void resize(int w, int h) override {
		logMessage("graphics resized %d %d", w, h);
		context->resize(w, h);
	}
	
	virtual void draw(double dt) override {
		// logMessage("frame redrawed dt = %lf", dt);
		// graphics.draw();
		context->requestDraw(dt);
	}
};

class PointerHandler : public media::Pointer::Handler {
public:
	PointerHandler() = default;
	virtual ~PointerHandler() = default;
	
	virtual void move(int buttons, ivec2 from, ivec2 to) override {
		/*
		logMessage(
		      "pointer moved from {%d, %d} to {%d, %d}, buttons: %d",
		      from.x(), from.y(), to.x(), to.y(), buttons
		      );
		*/
	}
	
	virtual void up(int button, ivec2 pos, int index) override {
		logMessage(
		      "pointer upped. button: %d, pos: {%d, %d}, index: %d",
		      button, pos.x(), pos.y(), index
		      );
	}
	
	virtual void down(int button, ivec2 pos, int index) override {
		logMessage(
		      "pointer downed. button: %d, pos: {%d, %d}, index: %d",
		      button, pos.x(), pos.y(), index
		      );
	}
	
	virtual void click(int button, ivec2 pos, int index) override {
		logMessage(
		      "pointer clicked. button: %d, pos: {%d, %d}, index: %d",
		      button, pos.x(), pos.y(), index
		      );
	}
	
	virtual void scroll(ivec2 pos, ivec2 val) override {
		logMessage(
		      "pointer scroll. pos: {%d, %d}, value: {%d, %d}",
		      pos.x(), pos.y(), val.x(), val.y()
		      );
	}
};

class AppHandler : public media::App::Handler {
public:
	virtual void create() override {
		GraphicsHandler *gh = new GraphicsHandler;
		PointerHandler *ph = new PointerHandler;
		super->getGraphics()->setHandler(gh);
		super->getPointer()->setHandler(ph);
		logMessage("app created");
	}
	
	virtual void destroy() override {
		delete super->getGraphics()->getHandler();
		delete super->getPointer()->getHandler();
		logMessage("app destroyed");
	}
};

MEDIA_SET_APP_HANDLER(AppHandler)
