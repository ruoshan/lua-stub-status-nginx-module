
/*
 * Copyright (C) Ruoshan Huang
 */

#ifdef (NGX_STAT_STUB)

#ifndef DDEBUG
#define DDEBUG 0
#endif
#include "ddebug.h"


#include <ngx_core.h>
#include <ngx_http.h>
#include <lauxlib.h>
#include "ngx_http_lua_api.h"


ngx_module_t ngx_http_lua_stub_status_module;

extern ngx_atomic_t  *ngx_stat_accepted;
extern ngx_atomic_t  *ngx_stat_handled;
extern ngx_atomic_t  *ngx_stat_requests;
extern ngx_atomic_t  *ngx_stat_active;
extern ngx_atomic_t  *ngx_stat_reading;
extern ngx_atomic_t  *ngx_stat_writing;
extern ngx_atomic_t  *ngx_stat_waiting;

static ngx_int_t ngx_http_lua_stub_status_init(ngx_conf_t *cf);
static int       ngx_http_lua_stub_status(lua_State *L);

static ngx_http_module_t ngx_http_lua_stub_status_ctx = {
    NULL,                           /* preconfiguration */
    ngx_http_lua_stub_status_init,     /* postconfiguration */
    NULL,                           /* create main configuration */
    NULL,                           /* init main configuration */
    NULL,                           /* create server configuration */
    NULL,                           /* merge server configuration */
    NULL,                           /* create location configuration */
    NULL                            /* merge location configuration */
};


ngx_module_t ngx_http_lua_stub_status_module = {
    NGX_MODULE_V1,
    &ngx_http_lua_stub_status_ctx,  /* module context */
    NULL,                           /* module directives */
    NGX_HTTP_MODULE,                /* module type */
    NULL,                           /* init master */
    NULL,                           /* init module */
    NULL,                           /* init process */
    NULL,                           /* init thread */
    NULL,                           /* exit thread */
    NULL,                           /* exit process */
    NULL,                           /* exit master */
    NGX_MODULE_V1_PADDING
};


static ngx_int_t ngx_http_lua_stub_status_init(ngx_conf_t *cf) {
    if (ngx_http_lua_add_package_preload(cf, "ngx.stub_status", ngx_http_lua_stub_status)
        != NGX_OK) {
        return NGX_ERROR;
    }

    return NGX_OK;
}

static int
ngx_http_lua_stub_status(lua_State *L) {
    lua_createtable(L, 0, 7);

    lua_pushinteger(L, *ngx_stat_active);
    lua_setfield(L, -2, "active");

    lua_pushinteger(L, *ngx_stat_accepted);
    lua_setfield(L, -2, "accepted");

    lua_pushinteger(L, *ngx_stat_handled);
    lua_setfield(L, -2, "handled");

    lua_pushinteger(L, *ngx_stat_requests);
    lua_setfield(L, -2, "requests");

    lua_pushinteger(L, *ngx_stat_reading);
    lua_setfield(L, -2, "reading");

    lua_pushinteger(L, *ngx_stat_writing);
    lua_setfield(L, -2, "writing");

    lua_pushinteger(L, *ngx_stat_waiting);
    lua_setfield(L, -2, "waiting");

    return 1;
}


#endif /* NGX_STAT_STUB */
