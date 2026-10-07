/*
 * file:     shinka_demo_view_p03.c
 * unit:     yes
 * function: func_02205AC0, func_02205B24, func_02205B60, func_02205B64
 * address:  0x02205AC0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02208CA0 0x02208CA0 data a4
 *   d_02208D1C 0x02208D1C data a4
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 */
#include "../../matched/include/G_02208D1C.h"

struct BgTemplate;
struct DispConfig;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u32 id;
    u8 data[0x20];
    u32 len;
    u32 mode;
} Entry;

typedef unsigned short u16;

extern void func_02082BCC(void *, int, int);
extern void func_0203F8F4(void *);
extern void func_02045088(void *);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8, u8);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
void func_02205AC0(void *a, void *b);
void func_02205B24(void *p);
void func_02205B60(void *a0);
void func_02205B64(void *a0);
extern u8 d_02208CA0[];
extern struct G_02208D1C d_02208D1C[];


/*
 * Twin of func_02205A34: the `(int)i` cast on the id read keeps the element
 * address from being hoisted above the guard.
 */
void func_02205AC0(void *a, void *b)
{
    u32 i;

    func_02082BCC(a, 0, 4);
    func_0203F8F4(b);
    func_02045088(b);
    func_0203FC28((struct DispConfig *)d_02208CA0);
    for (i = 0; i < 6; i++) {
        u32 v = d_02208D1C[(int)i].id;
        if (v <= 3) {
            Entry *e = &((Entry *)d_02208D1C)[i];
            func_0203FCA0((u8)v, (const struct BgTemplate *)e->data, (u8)e->len);
            func_020414AC(v);
            func_02040588(v, e->mode);
        }
    }
}

void func_02205B24(void *p) {u32 i;for(i=0;i<6;i++){u32 id=*(u32 *)(((char *)&d_02208D1C)+i*44);if(id<=3)func_020403F4((u8)id);}func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}


/*
 * extent: two trailing bytes of zero alignment padding.
 */
void func_02205B60(void *a0) {}

void func_02205B64(void *a0){func_020419E4();}
