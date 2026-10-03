/*
 * function: func_021E91E8
 * address:  0x021E91E8
 * packet:   pkt_ov093_021E91E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT*
 *
 * symbols:
 *   func_021F745C  0x021F745C  thumb  ov094
 *   func_021F7544  0x021F7544  thumb  ov094
 *   func_021F7C0C  0x021F7C0C  thumb  ov094
 *   func_021F7C2C  0x021F7C2C  thumb  ov094
 *   func_021F7CFC  0x021F7CFC  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021F80FC  0x021F80FC  thumb  ov094
 *   func_020307B0  0x020307B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_0201BD28  0x0201BD28  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_021E95B4  0x021E95B4  thumb  ov093
 *   func_021E95C4  0x021E95C4  thumb  ov093
 *   func_021E95D4  0x021E95D4  thumb  ov093
 *   func_021E95E4  0x021E95E4  thumb  ov093
 *   func_021E95F4  0x021E95F4  thumb  ov093
 *   func_021E9604  0x021E9604  thumb  ov093
 *   func_021E9614  0x021E9614  thumb  ov093
 *   func_021E9624  0x021E9624  thumb  ov093
 *   func_021E9634  0x021E9634  thumb  ov093
 *   func_021E9D04  0x021E9D04  thumb  ov093
 *   func_021E9E80  0x021E9E80  thumb  ov093
 *   func_021EA614  0x021EA614  thumb  ov093
 *   func_021EA65C  0x021EA65C  thumb  ov093
 *   func_021EA6F4  0x021EA6F4  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 *   func_021EA720  0x021EA720  thumb  ov093
 *   func_021EA730  0x021EA730  thumb  ov093
 *   func_021EA7C8  0x021EA7C8  thumb  ov093
 *   func_021EA7E8  0x021EA7E8  thumb  ov093
 *   func_021EAF00  0x021EAF00  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EAF78  0x021EAF78  thumb  ov093
 *   func_021EB028  0x021EB028  thumb  ov093
 *   func_021EB32C  0x021EB32C  thumb  ov093
 *   func_021EB52C  0x021EB52C  thumb  ov093
 *   func_021ED118  0x021ED118  thumb  ov093
 *   func_021ED1B0  0x021ED1B0  thumb  ov093
 *   func_021ED250  0x021ED250  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *
 * note (2026-10-03, wave B3 lane 01): every instruction, branch and pool word
 * matches (972 bytes, jump table included). The verdict is capped by the 8
 * calls to 0x021E95B4/95C4/95D4/95E4/95F4/9604/9614/9624: these are Thumb
 * bx-pc interworking veneers (bx pc; nop; ldr ip,[pc]; bx ip; .word) that the
 * linker placed right after this function. They have no label and no witness
 * outside this range, and C cannot produce them, so no witness file is
 * possible. The trailing star is the same 128 veneer bytes counted in the
 * listing extent (1100 = 972 + 8*16). It becomes EXACT when the Thumb bx-pc
 * veneer class is attested by the tools (out of scope for lanes).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u32 x0;             /* 0x000 */
    u8 pad4[0xA8];
    u32 xAC;            /* 0x0AC */
    u8 padB0[4];
    u32 xB4;            /* 0x0B4 */
    u32 xB8;            /* 0x0B8 */
    u32 xBC;            /* 0x0BC */
    u32 xC0;            /* 0x0C0 */
    u32 xC4;            /* 0x0C4 */
    u8 padC8[0x175 - 0xC8];
    u8 b175;            /* 0x175 */
    u8 pad176[0x17C - 0x176];
    u32 x17C;           /* 0x17C */
    u32 x180;           /* 0x180 */
    u16 h184;           /* 0x184 */
} Obj;

typedef struct Work {
    u32 heap;
    int timer;
} Work;

extern u32 func_021F745C(u32 a, u32 b, u16 c);
extern void func_021F7544(u32 a, u32 b, u16 c);
extern void func_020307B0(u32 a);
extern void func_021EB028(u32 a);
extern void func_021E95B4(u32 a);
extern u32 func_02045B38(int a, int b, int c, u16 d);
extern void func_021EB32C(u32 a, int b);
extern int func_021EB52C(u32 a);
extern u8 *func_021E9634(Obj *p, u32 k);
extern void func_021EAF18(void *msg, int a, int id);
extern u8 func_021D5440(u8 *p);
extern void func_021EAF50(void *msg, int v);
extern void func_021EAF78(void *msg, u8 v);
extern void func_021EA65C(Obj *p, void *msg);
extern void func_021EA614(Obj *p, void *msg);
extern void func_021E9604(u32 a, u32 b, u8 c, u32 d);
extern int func_021E95C4(u32 a);
extern void func_021E95D4(u32 a, u32 b, u32 c);
extern int func_021E95E4(u32 a);
extern void func_021EA6F4(void *p, u8 b, u16 c);
extern void func_021E9624(u32 a);
extern int func_021EA710(Obj *p);
extern int func_021E95F4(u32 a);
extern u32 func_0201BD28(int a, int b);
extern void func_021ED118(u32 p, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u8 a7);
extern int func_021ED1B0(u32 a);
extern int func_021D59B4(u8 *p, int k);
extern int func_0209C0A4(int a, int b);
extern void func_021F80FC(int a, int b);
extern void func_021F7C2C(int a, int b);
extern void func_021EAF00(Obj *p, u32 v);
extern int func_021ED250(u32 a);
extern void func_021EA7C8(Obj *p, int v);
extern int func_021EA7E8(Obj *p, int v);
extern void func_02045CAC(u32 heap, int a, u32 b);
extern void func_021EA730(Obj *p, u32 a, int b, int c);
extern int func_021E9614(u32 a);
extern void func_021E9D04(Obj *p, int a, int b, int c, int d, int e);
extern int func_021E9E80(Obj *p);
extern int func_021F7EB4(void);
extern void func_021F7CFC(int a, int b, int c, int d, int e);
extern int func_021EA720(Obj *p);
extern void func_02005D90(u32 a, u32 b);
extern int func_02005F38(void);
extern void func_021F7C0C(void);
extern void func_02045C04(u32 heap);

int func_021E91E8(Obj *p, int *state, Work *w)
{
    switch (*state) {
    case 0: {
        u32 h = func_021F745C(p->x0, p->x17C, p->h184);
        func_021F7544(h, p->xB4, p->h184);
        func_020307B0(h);
        func_021EB028(p->x17C);
        func_021E95B4(p->x180);
        w->heap = func_02045B38(0, 2, 0x14, p->h184);
        w->timer = 0;
        (*state)++;
        break;
    }
    case 1:
        func_021EB32C(p->x17C, 0);
        (*state)++;
        break;
    case 2:
        if (func_021EB52C(p->x17C)) {
            u8 msg[0x24];
            u8 *v = func_021E9634(p, 0);
            func_021EAF18(msg, 1, 0x45);
            func_021EAF50(msg, func_021D5440(v));
            func_021EAF78(msg, 0);
            func_021EA65C(p, msg);
            (*state)++;
        }
        break;
    case 3:
        p->xBC = (u32)func_021E9634(p, 0);
        p->xC0 = func_021D5440((u8 *)p->xBC);
        p->xB8 = 0;
        p->xC4 = 0;
        p->b175 = 0;
        func_021E9604(p->x180, p->xBC, p->b175, 0);
        (*state)++;
        break;
    case 4:
        if (func_021E95C4(p->x180)) {
            func_021E95D4(p->x180, p->xBC, p->xB8);
            (*state)++;
        }
        break;
    case 5:
        if (func_021E95E4(p->x180)) {
            func_021EA6F4(p, func_021D5440(func_021E9634(p, 0)), 1);
            func_021E9624(p->x180);
            (*state)++;
        }
        break;
    case 6:
        if (func_021EA710(p) && func_021E95F4(p->x180)) {
            func_021ED118(p->x17C, 0, 1, 1, func_0201BD28(1, 0x1B), 0, 0);
            (*state)++;
        }
        break;
    case 7:
        if (func_021ED1B0(p->x17C)) {
            func_021F80FC(1, func_0209C0A4(func_021D59B4(func_021E9634(p, 1), 0xE), 6));
            func_021F7C2C(1, 1);
            func_021EAF00(p, 0x564);
            (*state)++;
        }
        break;
    case 8:
        if (func_021ED250(p->x17C)) {
            func_021EA6F4(p, func_021D5440(func_021E9634(p, 1)), 0x2B);
            (*state)++;
        }
        break;
    case 9:
        if (func_021EA710(p)) {
            func_021ED118(p->x17C, 1, 0, 0x2B, func_0201BD28(0x2B, 0x1B), 0, 0);
            (*state)++;
        }
        break;
    case 10:
        if (func_021ED1B0(p->x17C)) {
            func_021EA7C8(p, 0);
            (*state)++;
        }
        break;
    case 11:
        if (func_021EA7E8(p, 0)) {
            u8 msg[0x24];
            u8 *v = func_021E9634(p, 0);
            func_021EAF18(msg, 2, 0x5D);
            func_021EAF50(msg, func_021D5440(v));
            func_021EAF78(msg, 0);
            func_021EA614(p, msg);
            (*state)++;
        }
        break;
    case 12:
        if (func_021EA710(p)) {
            func_02045CAC(w->heap, 0, p->xAC);
            func_021EA730(p, p->xAC, 0, 0);
            w->timer = 0x3C;
            (*state)++;
        }
        break;
    case 13:
        if (func_021EA710(p) && --w->timer == 0) {
            func_021E9604(p->x180, p->xBC, p->b175, p->xB8);
            (*state)++;
        }
        break;
    case 14:
        if (func_021E9614(p->x180)) {
            func_021E9D04(p, 2, 0, 0, 1, 0);
            (*state)++;
        }
        break;
    case 15:
        if (func_021E9E80(p)) {
            func_02045CAC(w->heap, 1, p->xAC);
            func_021EA730(p, p->xAC, 0, 0);
            func_021E9624(p->x180);
            (*state)++;
        }
        break;
    case 16:
        if (func_021EA710(p) && !func_021F7EB4()) {
            func_021F7CFC(1, 4, 3, 1, 0);
            (*state)++;
        }
        break;
    case 17:
        if (!func_021F7EB4()) {
            u8 msg[0x24];
            u8 *v = func_021E9634(p, 1);
            func_021EAF18(msg, 1, 0x41);
            func_021EAF50(msg, func_021D5440(v));
            func_021EA614(p, msg);
            (*state)++;
        }
        break;
    case 18:
        if (func_021EA720(p)) {
            func_02005D90(0x518, 0xFFFF);
        }
        if (func_021EA710(p)) {
            (*state)++;
        }
        break;
    case 19:
        if (!func_02005F38()) {
            func_021F7C0C();
            func_02045C04(w->heap);
            (*state)++;
        }
        break;
    case 20:
        return 1;
    }
    return 0;
}
