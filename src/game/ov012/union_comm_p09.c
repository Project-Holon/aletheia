/*
 * file:     union_comm_p09.c
 * unit:     yes
 * function: func_02173518, func_02173524, func_0217357C, func_021735FC, func_02173614, func_02173650
 * address:  0x02173518
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   memcmp        0x0203EFC8  arm
 *   MI_CpuCopy8   0x02082D44  arm
 */
#include "../../matched/include/Obj19230.h"

struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 mac[6];
    u8 f6;
    u8 b0 : 1;
    u8 b1 : 1;
} Rec;

typedef struct {
    struct { void *f0; } *head;
} Work;

typedef struct Entry { u8 mac[6]; u8 low6 : 4; u8 f6 : 4; u8 lo : 3; u8 used : 1; u8 hi : 4; u8 body[0x5c]; u8 mac2[6]; } Entry;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_02087C6C(void *p);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern int memcmp(const void *a, const void *b, int n);
extern void MI_CpuCopy8(const void *src, void *dst, int n);
void func_02173518(unsigned char *p);
void func_02173524(Work *w, u8 *p);
int func_0217357C(u8 *self, const u8 *mac, u8 a2, u8 a3);
int func_021735FC(u8 *self, const Entry *p);
void func_02173614(u8 *self, const u8 *mac);
void func_02173650(int a, u8 *b);

void func_02173518(unsigned char *p)
{
    p[0x19] = 0xff;
    p[0x1b] = 0xff;
    p[0x1a] = 0xff;
}


void func_02173524(Work *w, u8 *p)
{
    Rec *r;

    func_02082BCC(p, 0, 0x4c);
    func_02173518(p);
    r = (Rec *)(p + 0x1c);
    func_02087C6C(r);
    r->f6 = func_02008554(w->head->f0);
    r->b0 = (u32)func_02008550(w->head->f0);
    r->b1 = 1;
    ((struct Obj19230 *)p)->f44 = 0xFFFF;
}


int func_0217357C(u8 *self, const u8 *mac, u8 a2, u8 a3)
{
    int j;
    Rec *r;
    int i;
    Rec *e;

    i = 0;
    r = (Rec *)(self + 0x1c);
    for (; i < 5; i++) {
        if (r[i].b1 == 1 && memcmp(mac, &r[i], 6) == 0) {
            return i;
        }
    }
    for (j = 0; j < 5; j++) {
        e = (Rec *)(self + 0x1c) + j;
        if (e->b1 == 0) {
            MI_CpuCopy8(mac, e, 6);
            e->f6 = a2;
            e->b0 = a3;
            e->b1 = 1;
            return j;
        }
    }
    return 0;
}

int func_021735FC(u8 *self, const Entry *p) { return func_0217357C(self, p->mac2, p->f6, p->used); }


void func_02173614(u8 *self, const u8 *mac)
{
    int i;
    Rec *r;

    i = 0;
    r = (Rec *)(self + 0x1c);
    for (; i < 5; i++) {
        if (r[i].b1 == 1 && memcmp(mac, &r[i], 6) == 0) {
            func_02082BCC(&r[i], 0, 8);
            return;
        }
    }
}


void func_02173650(int a, u8 *b)
{
    func_02173614((u8 *)a, b + 0x64);
}
