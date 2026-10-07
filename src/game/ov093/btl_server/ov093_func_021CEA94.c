/*
 * function: func_021CEA94
 * address: 0x021CEA94
 * packet: pkt_ov093_021CEA94
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * witnesses: four ov093 blocker leaves 021E98AC, 021E98B4,
 * 021D7EF0, 021E9920 filed and individually shard-verified first.
 * lever: packed unsigned bitfields plus narrow caller extern CF5B0 move;
 * record declared before sub settles r6/r7 allocation (one variant).
 * interface: CF5B0 own source takes u32 move, but original narrows id at
 * 021CEBC6/021CEBCC; u16 extern preserves observed caller truncation.
 * CE3B4 ignores r1 but caller explicitly supplies p+0x58, retained here.
 * semantics: word bitfields use unsigned shifts; all dynamic address adds
 * and scaling are u32 modulo 2^32, without assuming selector/index bounds.
 * Byte increment is promoted in 0..255 then narrowed; all locals initialized
 * on each path to a use. The branch to state 4 has no uninitialized outputs.
 * symbols:
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021CF524 0x021CF524 thumb ov093
 *   func_021CE150 0x021CE150 thumb ov093
 *   func_021CF220 0x021CF220 thumb ov093
 *   func_021CE3C8 0x021CE3C8 thumb ov093
 *   func_021CE4D0 0x021CE4D0 thumb ov093
 *   func_021CED4C 0x021CED4C thumb ov093
 *   func_021CECB4 0x021CECB4 thumb ov093
 *   func_021E97BC 0x021E97BC thumb ov093
 *   func_021E9808 0x021E9808 thumb ov093
 *   func_021CE0BC 0x021CE0BC thumb ov093
 *   func_021E98AC 0x021E98AC thumb ov093
 *   func_021E98B4 0x021E98B4 thumb ov093
 *   func_021D8454 0x021D8454 thumb ov093
 *   func_021B9AB0 0x021B9AB0 thumb ov093
 *   func_021D832C 0x021D832C thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021CF5B0 0x021CF5B0 thumb ov093
 *   func_021EAF78 0x021EAF78 thumb ov093
 *   func_021CE3B4 0x021CE3B4 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D8340 0x021D8340 thumb ov093
 *   func_021D83FC 0x021D83FC thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021D7EF0 0x021D7EF0 thumb ov093
 *   func_021E98BC 0x021E98BC thumb ov093
 *   func_021E9920 0x021E9920 thumb ov093
 *   func_021E98E8 0x021E98E8 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021E9858 0x021E9858 thumb ov093
 */
#include "../../../matched/include/Obj00434.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 kind:4; u32 sub:3; u32 id:16; u32 rest:9; } Record;
struct Unk021D82D0;
struct UtilWork;
extern u32 func_021B8588(void **p);
extern u32 func_021CF524(u32, void *, u32);
extern void func_021CE150(u8 *p, void *q);
extern u32 func_021CF220(u8 *, int *);
extern int func_021CE3C8(u8 *, int *);
extern int func_021CE4D0(u8 *, u32 *);
extern u32 func_021CED4C(u8 *, int *);
extern void func_021CECB4(u8 *, void *);
extern void func_021E97BC(char *p, u8 *a, int b);
extern void func_021E9808(char *p, u32 *q, int c);
extern int func_021CE0BC(u8 *p, void *q);
extern void func_021E98AC(void *);
extern u32 func_021E98B4(void *);
extern u32 func_021D8454(u32 *);
extern int func_021B9AB0(int);
struct Unk021D82FC;
extern u32 func_021D832C(struct Unk021D82FC *p);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern int func_021CF5B0(u8 *g, void *m, u32 move, void *out);
extern void func_021EAF78(u8 *, u8);
extern void func_021CE3B4(u8 *p, void *q);
extern int func_021D5B68(void *);
extern u32 func_021D8340(u32 *);
extern void func_021D83FC(u32 *p, u32 sub);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u32 func_021D7EF0(u32);
extern void func_021E98BC(char *p, u8 *a, int b);
extern void func_021E9920(void *);
extern int func_021E98E8(char *p);
extern int func_021EA710(u32 *p);
extern void func_021E9858(char *p);

int func_021CEA94(u8 *p, u32 *state)
{
    void *m;
    u32 slot, k;
    u32 *record;
    u8 sub;
    switch (*state) {
    case 0:
        if (func_021B8588(((struct Obj00434 *)p)->f0) != 3) {
            if (func_021CF524((u32)p, ((struct Obj00434 *)p)->f8, *(u32 *)&((struct Obj00434 *)p)->fC))
                func_021CE150(p, (void *)((u32)func_021CF220));
            else *state = 1;
        } else {
            func_021CECB4(p, p + 0xa4);
            *state = 2;
        }
        break;
    case 1:
        func_021E97BC(((struct Obj00434 *)p)->f54, (u8 *)(*(u32 *)&((struct Obj00434 *)p)->f8), *(u32 *)&((struct Obj00434 *)p)->fC);
        *state = 3;
        break;
    case 2:
        func_021E9808(((struct Obj00434 *)p)->f54, (u32 *)(p + 0xa4), *(int *)&((struct Obj00434 *)p)->fC);
        *state = 3;
        break;
    case 3:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E98AC(((struct Obj00434 *)p)->f54);
            return 0;
        }
        if (func_021E98B4(((struct Obj00434 *)p)->f54)) {
            k = func_021D8454(*(u32 * *)&((struct Obj00434 *)p)->fC);
            if (k == 0) func_021CE150(p, (void *)((u32)func_021CE4D0));
            else if (k == 5) func_021CE150(p, (void *)((u32)func_021CF220));
            else {
                m = ((struct Obj00434 *)p)->f8;
                record = *(u32 * *)&((struct Obj00434 *)p)->fC;
                sub = 0;
                slot = p[0x11d];
                if (func_021B8588(((struct Obj00434 *)p)->f0) == 3) {
                    sub = (u8)((Record *)(p + 0xbc))->sub;
                    slot = func_021B9AB0(sub);
                    m = *(void **)((u32)p + slot * 8U + 0xa4U);
                }
                if (func_021D832C((struct Unk021D82FC *)record)) {
                    p[0x1b0] = slot;
                    p[0x1b1] = func_021D5778(m, (u16)((Record *)record)->id);
                    if (p[0x1b1] != 4) {
                        func_021CE150(p, (void *)((u32)func_021CED4C));
                        return 0;
                    }
                }
                if (func_021CF5B0(p, m, (u16)((Record *)record)->id, p + 0x58)) {
                    func_021EAF78(p + 0x58, 0xff);
                    func_021CE3B4(p, p + 0x58);
                    *state = 7;
                } else {
                    if (func_021B8588(((struct Obj00434 *)p)->f0) == 3 && sub != 0 && sub != 1 && !func_021D5B68(m)) {
                        k = func_021D8340((u32 *)(p + 0xc0));
                        record = *(u32 * *)&((struct Obj00434 *)p)->fC;
                        *(u32 *)&((struct Obj00434 *)p)->fC = (u32)record + 4U;
                        func_021D83FC(record, sub);
                        func_021D82D0(((struct Obj00434 *)p)->fC, k, 6);
                        ++p[0x1af];
                    }
                    *state = 4;
                }
            }
        }
        break;
    case 4:
        if (func_021D7EF0(func_021B8588(((struct Obj00434 *)p)->f0))) *state = 5;
        else func_021CE150(p, (void *)((u32)func_021CF220));
        break;
    case 5:
        func_021E98BC(((struct Obj00434 *)p)->f54, (u8 *)(*(u32 *)&((struct Obj00434 *)p)->f8), *(u32 *)&((struct Obj00434 *)p)->fC);
        *state = 6;
        break;
    case 6:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E9920(((struct Obj00434 *)p)->f54);
            return 0;
        }
        k = func_021E98E8(((struct Obj00434 *)p)->f54);
        if (k == 1) func_021CE150(p, (void *)((u32)func_021CF220));
        else if (k == 2) *state = 1;
        break;
    case 7:
        if (func_021EA710(((struct Obj00434 *)p)->f54)) {
            func_021E9858(((struct Obj00434 *)p)->f54);
            *state = 3;
        }
        break;
    }
    return 0;
}
