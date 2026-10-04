/*
 * function: func_0215B0B4
 * address:  0x0215B0B4
 * packet:   pkt_0215B0B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020089C0  0x020089C0  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02025C88  0x02025C88  thumb
 *   func_020089F4  0x020089F4  thumb
 *   func_02008A00  0x02008A00  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct SaveBlock;
struct Big;
struct Sub020089A8Obj;
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_020127A4(struct SaveBlock *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub020089A8Obj *func_020089C0(void *sys);
struct Sub0200852CObj;
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u32 func_02025C88(u32 x);
extern u8 func_020089F4(const struct Sub020089A8Obj *obj);
extern int func_02008A00();

int func_0215B0B4(int a0, int a1)
{
    int t4;
    int t6;
    char *sb;
    void *p;
    struct Sub020089A8Obj *obj;
    unsigned short *v0;
    unsigned short *v1;
    void *v2;

t6 = a0 + 0;
t4 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215B0BE:
a0 = t6 + 0;
a1 = t4 + 0;
    v1 = func_02159AE8((void *)a0, (void *)a1);
loc_0215B0C8:
a0 = t4 + 0;
    v2 = func_0215A5E4((void *)a0);
loc_0215B0D0:
    sb = func_020127A4((struct SaveBlock *)v2);
loc_0215B0D6:
    p = func_02012EBC((struct Big *)v2);
loc_0215B0DE:
    obj = func_020089C0(p);
loc_0215B0E2:
sb = sb + 0x20;
    a0 = func_02008554((const struct Sub0200852CObj *)sb);
loc_0215B0EC:
    a0 = func_02025C88(a0);
loc_0215B0F0:
*(u16 *)((char *)v1) = a0;
    a0 = func_020089F4(obj);
loc_0215B0F8:
*(u16 *)((char *)v0) = a0;
    a0 = func_02008A00(obj);
loc_0215B100:
a0 = 0;
    return a0;}
