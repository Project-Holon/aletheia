/*
 * function: func_021D0770
 * address: 0x021D0770
 * packet: pkt_ov093_021D0770
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: nested one-word aggregate return removes its extra frame word;
 *   named count/bytes reproduce original final read/store order. Three
 *   iteration runs, two scheduling variants; no prior compiles.
 * semantic: state/cursor arithmetic is unsigned; byte counters promote
 *   safely and narrow on store. CF81C writes all four availability bytes
 *   before return; CFBF0 writes the single output byte on every nonzero
 *   return path. Full-width pointer payloads retain their original bits.
 * symbols:
 *   func_021CFBA4 0x021CFBA4 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021CF470 0x021CF470 thumb ov093
 *   func_021D3DC4 0x021D3DC4 thumb ov093
 *   func_021D8358 0x021D8358 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021CFBF0 0x021CFBF0 thumb ov093
 *   func_021D8394 0x021D8394 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021D06C8 0x021D06C8 thumb ov093
 *   func_021B9AB0 0x021B9AB0 thumb ov093
 *   func_021D83FC 0x021D83FC thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D6314 0x021D6314 thumb ov093
 *   func_021E8B80 0x021E8B80 thumb ov093
 *   func_021D81F8 0x021D81F8 thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021CF524 0x021CF524 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021CF81C 0x021CF81C thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021880BC 0x021880BC thumb ov096
 *   func_021CF58C 0x021CF58C thumb ov093
 *   func_02187FB0 0x02187FB0 thumb ov096
 *   func_02188134 0x02188134 thumb ov096
 *   func_02188140 0x02188140 thumb ov096
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D8414 0x021D8414 thumb ov093
 */
#include "../include/Obj00464.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 v; } Word;
extern void func_021CFBA4(s8 *);
struct QG;
struct S2;
struct Unk021D62A8;
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
extern void func_021D8434(u8 *);
extern u32 func_021CF470(u8 *, void *, u8 *);
extern u32 func_021D3DC4(u8 *, void *, void *);
struct Unk021D82D0;
extern void func_021D8358(u32 *p, u32 id, u32 sub, u32 val);
extern void *func_021B86B8(void ***);
extern int func_021CFBF0(u8 *, void *, u32, u8 *);
extern void func_021D8394(void *, u8, u32);
extern u32 func_021B8588(void **p);
extern u8 func_021D06C8(void *);
extern int func_021B9AB0(int);
extern void func_021D83FC(void *, int);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern Word func_021D6314(void *, int);
extern u16 func_021E8B80(Word);
extern u32 func_021D81F8(void *, void *, void *, u32, void *);
extern void func_021D82D0(void *, u32, u32);
extern u32 func_021CF524(u32, void *, u32);
extern u8 func_021D5448(struct QG *p);
extern u32 func_021CF81C(u8 *, void *, u8 *);
extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *, void *, u32);
extern void func_021880BC(int, u8 *, int);
extern void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q);
extern int func_02187FB0(u8 *);
extern u8 func_02188134(u8 *);
extern u8 func_02188140(u8 *);
extern u16 func_021D54C0(u8 *p, int i);
extern void func_021D8414(u32 *);
#define M (*(void **)(p+8))
#define R (*(u8 **)(p+12))
int func_021D0770(u8 *p, u32 *state)
{
    u8 available[4];
    u8 choice;
    u32 move;
    u32 slot;
    u32 sub;
    u32 result;
    u32 count;
    u32 bytes;
    switch (*state) {
    case 0:
        func_021CFBA4((s8 *)p);
        p[0x11d] = 0;
        p[0x1af] = 0;
        *state = 1;
    case 1:
        if (p[0x11d] >= p[0x11c]) break;
        M = func_021B9C00(((struct Obj00464 *)p)->f118, p[0x11d]);
        R = p+0x124+p[0x11d]*4;
        if (func_021D5B68(M)) {
            func_021D8434(R);
            goto complete;
        }
        if (func_021CF470(p,M,R)) goto complete;
        move = func_021D3DC4(p,M,((struct Obj00464 *)p)->f118);
        if (move) {
            func_021D8358((u32 *)R,move,p[0x11d],0);
            goto complete;
        }
        if (func_021B86B8(*(void *** *)&((struct Obj00464 *)p)->f0) && func_021CFBF0(p,M,p[0x11d],&choice)) {
            func_021D8394(R,p[0x11d],choice);
            goto complete;
        }
        if (func_021B8588(((struct Obj00464 *)p)->f0) == 3) {
            slot = func_021D06C8(p);
            if (slot != 1) {
                sub = func_021B9AB0(slot);
                func_021D83FC(R,slot);
                M = func_021B9C00(((struct Obj00464 *)p)->f118,sub);
                p[0x1af] = 1;
                R = (u8 *)((u32)R+4U);
            }
        }
        if (func_021D62C4(M,0x19)) {
            move = func_021E8B80(func_021D6314(M,0x19));
            result = func_021D81F8(((struct Obj00464 *)p)->f0,((struct Obj00464 *)p)->f4,M,move,p+0xf4);
            func_021D82D0(R,move,result);
            goto complete;
        }
        if (func_021CF524((u32)p,M,(u32)R)) *state = 3;
        func_021D5448(M);
        slot = func_021CF81C(p,M,available);
        if (slot != 4) {
            result = func_021B8D8C(((struct Obj00464 *)p)->f0,((struct Obj00464 *)p)->f4,func_021D5440(M));
            func_021880BC(*(int *)&((struct Obj00464 *)p)->fF0,available,result);
            *state = 2;
        } else {
            func_021CF58C((struct Unk021D82D0 *)((u32)R),(u8 *)((u32)p),M);
            goto complete;
        }
        break;
    case 2:
        if (func_02187FB0(*(u8 * *)&((struct Obj00464 *)p)->fF0)) break;
        slot = func_02188134(*(u8 * *)&((struct Obj00464 *)p)->fF0);
        if (slot != 4) {
            sub = func_02188140(*(u8 * *)&((struct Obj00464 *)p)->fF0);
            move = func_021D54C0(M,slot);
            func_021D82D0(R,move,sub);
        } else func_021D8414((u32 *)R);
complete:
        *state = 3;
        break;
    case 3:
        p[0x11d]++;
        count = p[0x11c];
        if (p[0x11d] >= count) {
            bytes = (count+p[0x1af])*4;
            *(u8 * *)&((struct Obj00464 *)p)->fD8 = p+0x124;
            ((struct Obj00464 *)p)->fDC = bytes;
            p[0x1af] = 0;
            return 1;
        }
        *state = 1;
        break;
    }
    return 0;
}
