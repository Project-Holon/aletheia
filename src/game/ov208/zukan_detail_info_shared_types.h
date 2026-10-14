#ifndef ZUKAN_DETAIL_INFO_SHARED_TYPES_H
#define ZUKAN_DETAIL_INFO_SHARED_TYPES_H

#include "zukan_detail_procsys_shared_types.h"
#include "zukan_detail_common_shared_types.h"

struct Ov208Buf;

struct Ov208Blend;

struct S;

struct Ov208Cur;

struct S {
    u8 pad0[0x424];
    u32 f424;
    u32 f428;
    u32 f42c;
    u32 f430;
    u32 f434;
};

typedef struct {
    char pad[0x1e0];
    int arr[0x7a];
} S;

#endif
