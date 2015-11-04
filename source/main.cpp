#include <media/media.hpp>
#include <graphics/graphics.h>

#include "graphics.hpp"

class GraphicsHandler : public media::Graphics::Handler {
private:
	GContext *context;
	// Graphics graphics;
	
	bool inited = false;
	static void callback(void *data) {
		static_cast<GraphicsHandler *>(data)->inited = true;
	}

public:
	GraphicsHandler() = default;
	virtual ~GraphicsHandler() = default;
	
	virtual void create() override {
		logMessage("graphics created");
		context = gCreateContext();
		gSetInitCallback(context, callback, static_cast<void *>(this));
		gInit(context);
	}
	
	virtual void destroy() override {
		logMessage("graphics destroyed");
		gDispose(context);
		gDestroyContext(context);
	}
	
	virtual void resize(int w, int h) override {
		logMessage("graphics resized %d %d", w, h);
		gResize(context, w, h);
	}
	
	virtual void draw(double dt) override {
		// logMessage("frame redrawed dt = %lf", dt);
		// graphics.draw();
		float m[4] = {100,0,0,100};
		if(inited) {
			gClear(context);
			gSetColorInt(context, G_RED);
			gTransform(context, m);
			gDrawCircle(context);
		}
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
