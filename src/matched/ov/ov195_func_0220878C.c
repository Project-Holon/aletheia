/*
 * function: func_0220878C
 * address:  0x0220878C
 * packet:   pkt_0220878C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02208C10 0x02208C10 thumb ov195
 *   func_02208C18 0x02208C18 thumb ov195
 *   func_02208C28 0x02208C28 thumb ov195
 *   func_02208C30 0x02208C30 thumb ov195
 *   func_02208A48 0x02208A48 thumb ov195
 *   func_02208B6C 0x02208B6C thumb ov195
 *   func_022089A4 0x022089A4 thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Anim {
    u16 heap;
    u16 pad02;
    u32 f04;
    u32 state;
    u32 wait;
    void *ptc;
} Anim;

extern void func_02208C10(Anim *p);
extern int func_02208C18(Anim *p);
extern void func_02208C28(Anim *p);
extern int func_02208C30(Anim *p);
struct Ptc;
extern void func_02208A48(struct Ptc *p, s32 timer);
extern void func_02208B6C(char *p);
extern void func_022089A4(struct Ptc *p);

void func_0220878C(Anim *p)
{
    switch (p->state) {
    case 0:
    case 1:
        break;
    case 2:
        func_02208C10(p);
        p->state = 3;
        break;
    case 3:
        if (func_02208C18(p)) {
            p->state = 4;
            p->wait = 3;
            func_02208A48(p->ptc, 0);
        }
        break;
    case 4:
        if (p->wait == 0) {
            func_02208C28(p);
            p->state = 5;
        } else {
            p->wait = p->wait - 1;
        }
        break;
    case 5:
        if (func_02208C30(p))
            p->state = 6;
        break;
    case 6:
    case 7:
        break;
    }
    func_02208B6C((char *)p);
    func_022089A4(p->ptc);
}
