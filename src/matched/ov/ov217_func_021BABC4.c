/*
 * function: func_021BABC4
 * address:  0x021BABC4
 * packet:   pkt_ov217_021BABC4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB974  0x021BB974  thumb  ov217
 *   func_021BACA0  0x021BACA0  thumb  ov217
 *   func_021BAE00  0x021BAE00  thumb  ov217
 *   func_021BAF70  0x021BAF70  thumb  ov217
 *   func_021BB190  0x021BB190  thumb  ov217
 *   func_021BB200  0x021BB200  thumb  ov217
 *   func_021BB710  0x021BB710  thumb  ov217
 *   func_021BB69C  0x021BB69C  thumb  ov217
 *   func_021BB484  0x021BB484  thumb  ov217
 *   func_021BB2B4  0x021BB2B4  thumb  ov217
 *   func_021BB534  0x021BB534  thumb  ov217
 *   func_021BB37C  0x021BB37C  thumb  ov217
 *   func_021BB784  0x021BB784  thumb  ov217
 *   func_021BB5F4  0x021BB5F4  thumb  ov217
 *   func_021BB84C  0x021BB84C  thumb  ov217
 *   func_021BAC90  0x021BAC90  thumb  ov217
 *   func_021BC5F0  0x021BC5F0  thumb  ov217
 *   func_021BC5D4  0x021BC5D4  thumb  ov217
 *   func_021BB908  0x021BB908  thumb  ov217
 *   func_021BB94C  0x021BB94C  thumb  ov217
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct S;
extern u32 func_021BB974(void *p);
extern void func_021BACA0(u8 *p);
extern void func_021BAE00(u8 *p);
extern void func_021BAF70(char *p);
extern void func_021BB190(u8 *p);
extern void func_021BB200(struct S *p);
extern void func_021BB710(u8 *p);
extern void func_021BB69C(u8 *p);
extern void func_021BB484(u8 *p);
extern void func_021BB2B4(char *p);
extern void func_021BB534(u8 *p);
extern void func_021BB37C(char *p);
extern void func_021BB784(struct S *p);
extern void func_021BB5F4(u8 *p);
extern void func_021BB84C(u8 *p);
extern u32 func_021BAC90(void *p);
extern void func_021BC5F0(u8 *a0);
extern void func_021BC5D4(int *p);
extern void CLACT_DrawSystem(void);
extern void func_021BB908(void *);
extern void func_021BB94C(u32 a0);

void func_021BABC4(void *self)
{
    switch (func_021BB974(self)) {
    case 0: func_021BACA0(self); break;
    case 1: func_021BAE00(self); break;
    case 2: func_021BAF70(self); break;
    case 3: func_021BB190(self); break;
    case 4: func_021BB200(self); break;
    case 6: func_021BB69C(self); break;
    case 5: func_021BB710(self); break;
    case 7: func_021BB484(self); break;
    case 8: func_021BB2B4(self); break;
    case 9: func_021BB534(self); break;
    case 10: func_021BB37C(self); break;
    case 11: func_021BB784(self); break;
    case 12: func_021BB5F4(self); break;
    case 13: func_021BB84C(self); break;
    case 14: break;
    }
    if (!func_021BAC90(self)) {
        func_021BC5F0(self);
        func_021BC5D4(self);
        CLACT_DrawSystem();
    }
    func_021BB908(self);
    func_021BB94C((u32)self);
}
