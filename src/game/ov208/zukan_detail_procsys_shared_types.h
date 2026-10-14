#ifndef ZUKAN_DETAIL_PROCSYS_SHARED_TYPES_H
#define ZUKAN_DETAIL_PROCSYS_SHARED_TYPES_H

struct Ov208Fsm;

struct Ov208Obj;

typedef unsigned short u16;

typedef unsigned int u32;

struct Ov208Obj { void *owner; int f4; int f8; int fc; int f10; };

typedef int (*Ov208FsmCallback)(struct Ov208Fsm *,int *,int,int,int);

struct Ov208Fsm { Ov208FsmCallback *callbacks; int state,counter,a,b; };

#endif
