/*
 * function: func_02173524
 * address:  0x02173524
 * packet:   pkt_ov012_02173524
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02173518  0x02173518  thumb  ov012
 *   func_02087C6C  0x02087C6C  arm
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 */
#include "../include/Obj19230.h"

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

extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_02173518(u8 *p);
extern void func_02087C6C(void *p);
struct Sub0200852CObj;
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);

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
