/*
 * function: func_021F546C
 * address:  0x021F546C
 * packet:   pkt_ov112_021F546C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Slot writer (172 bytes, 0x021F546C..0x021F5518): mode >= 7 sets slot mode-7 (stride 0x38) enabled and copies
 * four Vec records plus two halfwords; mode 4 and 5 copy in->b.x/y into p+0x20C/0x210 and p+0x218/0x21C style
 * word groups and set a flag. Different function from the ov194 one at the same address.
 *
 * 2026-10-05 (wave D5 lane 02): rebuilt from docs/notes/pkt_ov112_021F546C.c.txt. 170 bytes vs 172. The only
 * structural residue is the first block: the original keeps mode-7 in r4 and copies it (`subs r4,r0,#7;
 * movs r0,#0x38; adds r1,r4,#0; muls r1,r0,r1`) while the compiler multiplies in place. Tried: array index
 * &((Slot *)p)[mode-7], int and long and unsigned index, index declared before the if, a copy of mode, Slot *
 * parameter. All give 153 differing bytes (one shifted copy). Everything after the multiply is the same shape.
 *
 * symbols:
 */

typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { Vec a,b,c,d; u16 e,f; } Input;
typedef struct { int pad[5]; int enabled; Vec a,b,c,d; u16 e,f; } Slot;
typedef enum { M0=0, Mmax=0xffffffff } Mode;
void func_021F546C(unsigned mode, const Input *in, char *p)
{
    long index;
    int x,y;
    Slot *s;
    if (mode >= 7) {
        index = mode-7;
        p += index*56;
        s = (Slot *)p;
        s->enabled=1;
        s->a=in->a;
        s->b=in->b;
        s->e=in->e;
        s->f=in->f;
        s->c=in->c;
        s->d=in->d;
        return;
    }
    if (mode == 4) {
        y=in->b.y;
        x=in->b.x;
        *(int *)(p+524)=x;
        *(int *)(p+528)=y;
        *(int *)(p+532)=0;
        *(int *)(p+548)=1;
        return;
    }
    if (mode == 5) {
        y=in->b.y;
        x=in->b.x;
        *(int *)(p+536)=x;
        *(int *)(p+540)=y;
        *(int *)(p+544)=0;
        *(int *)(p+552)=1;
    }
}

