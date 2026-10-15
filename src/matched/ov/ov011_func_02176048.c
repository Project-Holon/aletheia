/*
 * function: INTRUDE_COMM_ReceiveJoinRequest
 * address:  0x02176048
 * packet:   pkt_ov011_02176048
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb  ov011
 *   DWCi_GetHostStatus  0x02175FB8  thumb  ov011
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   INTRUDE_COMM_SetSessionRequestSendFlag  0x02175920  thumb  ov011
 *   GF_STANDARD_GetTime  0x0203F4FC  arm
 */
#include "../include/Obj12438.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0_0 : 15;
    u32 f0_15 : 7;
    u32 f0_22 : 10;
    u32 kind : 4;
    u32 f4_4 : 28;
    u32 w8[4];
} Head;

typedef struct {
    u16 name[8];
    u8 b10;
    u8 pad11;
    u16 pad12;
} Name;

typedef struct {
    Head head;
    Name name;
    u8 b2C;
} Src;

typedef struct {
    Head head;
    Name name;
    u8 idx;
    u8 b2D;
    u8 b2E;
    u16 h30;
    u16 h32;
} Rec;

typedef struct {
    u8 state;
    Rec rec;
} Entry;

typedef struct {
    u8 pad0[0x78];
    Rec tmp;
    u8 padAC[0xE8 - 0xAC];
    Entry entries[1];
} Work;

extern void MI_CpuFill8(void *p, int v, int n);
extern int INTRUDE_COMM_IsSessionActive(u8 *p);
extern int DWCi_GetHostStatus(void *p, Src *src);
extern u32 GFL_NET_SYSTEM_GetConnectNum(void);
extern int GFL_NET_GetNegotiationNum(void);
extern void INTRUDE_COMM_SetSessionRequestSendFlag(void *p);
extern u32 GF_STANDARD_GetTime(void);

int INTRUDE_COMM_ReceiveJoinRequest(u8 *a0, Work *p, Src *src, int idx)
{
    Rec *tmp = &p->tmp;

    MI_CpuFill8(&p->entries[idx], 0, sizeof(Entry));
    if (INTRUDE_COMM_IsSessionActive(a0 + 0x1AC) == 1) {
        p->entries[idx].state = 2;
        return 0;
    }
    if (DWCi_GetHostStatus(a0 + 0x1AC, src) == 0) {
        p->entries[idx].state = 2;
        return 0;
    }
    if (src->head.kind == 0 || src->head.kind == 3) {
        if (GFL_NET_SYSTEM_GetConnectNum() != 2 || GFL_NET_GetNegotiationNum() != 2) {
            p->entries[idx].state = 4;
            return 0;
        }
    }
    tmp->head = src->head;
    tmp->name = src->name;
    tmp->idx = idx;
    tmp->b2D = src->name.b10;
    tmp->b2E = src->b2C;
    tmp->h30 = 10;
    tmp->h32 = src->head.f0_22;
    p->entries[idx].rec = *tmp;
    p->entries[idx].state = 1;
    INTRUDE_COMM_SetSessionRequestSendFlag(p);
    ((struct Obj12438 *)p)->f190 = GF_STANDARD_GetTime();
    *((u8 *)p + 0x19C) = 0;
    return 1;
}
