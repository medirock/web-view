#define WEBVIEW_IMPLEMENTATION
#include "webview.h"

void wrapper_webview_free(struct webview* w) {
	free(w);
}

struct webview* wrapper_webview_new(const char* title, const char* url, int width, int height, int resizable, int debug, webview_external_invoke_cb_t external_invoke_cb, void* userdata, const char *gtk_custom_css) {
	struct webview* w = (struct webview*)calloc(1, sizeof(*w));
	w->width = width;
	w->height = height;
	w->title = title;
	w->url = url;
	w->resizable = resizable;
	w->debug = debug;
	w->external_invoke_cb = external_invoke_cb;
	w->userdata = userdata;
	w-> gtk_custom_css = gtk_custom_css;
	if (webview_init(w) != 0) {
		wrapper_webview_free(w);
		return NULL;
	}
	return w;
}

void* wrapper_webview_get_userdata(struct webview* w) {
	return w->userdata;
}

