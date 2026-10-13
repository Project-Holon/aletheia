/*
 * function: MONOLITH_TOOL_CreateRowGrids
 * address:  0x021B9AE4
 * packet:   pkt_ov071_021B9AE4
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_Create  0x02043678  arm
 *   BMP_OAM_Create  0x020255A0  thumb
 *   gMonolithRowGridParam     0x021BAB10  data  a4
 */

typedef unsigned char u8;

typedef struct {
    void *f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
} Tmpl;

typedef struct {
    u8 pad00[0x2a0];
    void *a2a0[7];
    void *a2bc[7];
} Work;

typedef struct {
    u8 pad00[0x2c];
    void *f2c;
    u8 pad30[0x5c - 0x30];
    int f5c;
} Src;

typedef unsigned int   u32;
struct Bmp;
typedef unsigned short u16;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
struct Grid;
struct Param;
struct Sys;
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern const Tmpl gMonolithRowGridParam;

void MONOLITH_TOOL_CreateRowGrids(Work *p, Src *s)
{
    int i;
    Tmpl t;

    t = gMonolithRowGridParam;
    t.f08 = s->f5c;
    for (i = 0; i < 7; i++) {
        p->a2bc[i] = BMP_Create(0x17, 2, 0x20, 0x61);
        t.f00 = p->a2bc[i];
        p->a2a0[i] = BMP_OAM_Create(s->f2c, (const struct Param *)(&t));
    }
}
