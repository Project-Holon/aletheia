/*
 * function: func_0220D884
 * address:  0x0220D884
 * packet:   pkt_ov198_0220D884
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note 2026-10-05 (wD6 lane07): closed by a real Rec struct array indexed at each use (((Rec *)p)[idx].f) and p + i*8 + K at each use; the pool word is data d_02211AFF.
 * symbols:
 *   func_0220D884  0x0220D884  thumb  ov198
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_022110D4  0x022110D4  thumb  ov198
 *   func_0220BEB8  0x0220BEB8  thumb  ov198
 *   func_0220D920  0x0220D920  thumb  ov198
 *   func_020276C4  0x020276C4  thumb
 *   func_0220D988  0x0220D988  thumb  ov198
 *   d_02211AFF  0x02211AFF  data  a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {u8 lo:7,hi:1;} Bits;
struct Descriptor;
struct CharBuf;
extern void *func_02045770(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern int func_022110D4(u8 *, int);
extern void func_0220BEB8(u8 *p, int slot, u16 a2, u8 a3, u8 extra);
extern void func_0220D920(u8 *, int);
extern int func_020276C4(int a0);
extern void func_0220D988(u8 *, int);
extern u8 d_02211AFF[];
typedef struct { u8 pad0[4]; void *obj; u16 cnt; u8 pad1[0x1B-0xA]; Bits fl; u8 pad2[0x4C-0x1C]; } Rec;
void func_0220D884(u8 *p)
{
    s16 i;
    int idx;

    *(void **)(p + 0x253C) = d_02211AFF;
    for (i = 0; i < 6; i++) {
        BMP_Clear((struct CharBuf *)func_02045770(*(struct Descriptor **)(p + i * 8 + 0x1F70)), 0);
        idx = func_022110D4(p, i);
        if (((Rec *)p)[idx].cnt == 0) {
            *(u8 *)(p + i * 8 + 0x1F74) = 1;
        } else {
            func_0220BEB8(p, i, (u16)i, 0x20, 7);
            if (!((Rec *)p)[idx].fl.hi) {
                func_0220D920(p, (u8)i);
            }
            if (func_020276C4((int)(((Rec *)p)[idx].obj)) == 8) {
                func_0220D988(p, (u8)i);
            }
        }
    }
}
