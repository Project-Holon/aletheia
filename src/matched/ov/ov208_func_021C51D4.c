/*
 * function: func_021C51D4
 * address: 0x021C51D4
 * packet: pkt_ov208_021C51D4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02015EE8 0x02015EE8 thumb
 *   func_02064CBC 0x02064CBC arm
 *   func_02015E4C 0x02015E4C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Anm { u8 pad0[8]; u8 f8; u8 pad9[3]; u32 fc; };
struct Ov208Slot { void *obj; struct Ov208Anm *anm; };
extern void *func_02015EE8(void *p);
extern void func_02064CBC(void *p);
extern void func_02015E4C(void *p);
void func_021C51D4(struct Ov208Slot *s)
{
    if (s->obj != 0 && s->anm != 0) {
        void *r = func_02015EE8(s->obj);
        s->anm->f8 = 0;
        s->anm->fc = 0;
        func_02064CBC(r);
        func_02015E4C(s->obj);
    }
}
