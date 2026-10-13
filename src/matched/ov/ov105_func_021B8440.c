/*
 * function: func_021B8440
 * address: 0x021B8440
 * packet: pkt_ov105_021B8440
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021B8974 0x021B8974 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 objects[3]; u8 pad[0x24]; u8 digits[3]; u8 pad1; int state[3]; } Display;
extern const unsigned d_021B8974[];
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void func_021B8440(Display *p, unsigned n)
{
    u8 t;
    int i, j;
    t = n;
    if (t) { for (;;) { if (!t) break; t = t / 10; } }
    for (i = 0; i < 3; i++) CLACT_SetActorAnimSeq((struct Obj *)p->objects[i],0);
    for (j = 0; j < 3; j++) {
        p->digits[j] = n % d_021B8974[j+1] / d_021B8974[j];
        CLACT_SetActorAnimSeq((struct Obj *)p->objects[2-j],p->digits[j]+1);
    }
}
