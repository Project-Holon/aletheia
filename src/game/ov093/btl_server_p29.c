/*
 * file:     btl_server_p29.c
 * unit:     yes
 * function: func_021BF9A4, func_021BFA00, func_021BFA60, func_021BFBD0, func_021BFC08
 * address:  0x021BF9A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B9A6C  0x021B9A6C  thumb  ov093
 *   func_021BF324 0x021BF324 thumb ov093
 *   func_021C69B8 0x021C69B8 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021C6A04 0x021C6A04 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D7674 0x021D7674 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021D7908 0x021D7908 thumb ov093
 *   func_021D7B10 0x021D7B10 thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021CD568 0x021CD568 thumb ov093
 *   func_021C66AC 0x021C66AC thumb ov093
 *   func_021C5718 0x021C5718 thumb ov093
 *   func_021C6720 0x021C6720 thumb ov093
 *   func_021BFD24 0x021BFD24 thumb ov093
 *   func_021E896C 0x021E896C thumb ov093
 *   func_021C5C1C 0x021C5C1C thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C6878 0x021C6878 thumb ov093
 *   func_021C68A8 0x021C68A8 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021BFE60 0x021BFE60 thumb ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj07752.h"
#include "../../matched/include/Obj05190.h"
#include "../../matched/include/Obj21062.h"
#include "../../matched/include/Obj00003.h"

struct Unk021D62A8;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

struct Q { u16 h0; u8 pad[6]; u32 w8; };

typedef struct { u32 raw; } Word;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern u32 func_021B8588(void **p);
extern int func_0201BEB8(void *bag, int item);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern int func_021B9A6C(int a, u32 b);
extern int func_021BF324(u8 *, u8 *, u8 *);
extern int func_021C69B8(u8 *, u8 *, u32, u16);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021C6A04(u8 *, u8 *, u8 *, struct Q *);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D75A8(int, u32);
extern void func_021D7674(int, u32, u32, u32);
extern void func_021D7704(int, int);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern unsigned char func_021D7908(int a, int i);
extern u32 func_021D7B10(u32, u32);
extern int func_021B911C(void *, int);
extern u32 func_021D78AC(u32);
extern void func_021CD568(void *, u32, u32, ...);
extern int func_021C66AC(u8 *, u8 *, u32);
extern void func_021C5718(u8 *, u8 *, u32);
extern int func_021C6720(u8 *, u8 *, u32);
extern int func_021BFD24(u8 *, u8 *, int, u8 *, u16);
extern Word func_021E896C(int, int);
extern void func_021C5C1C(u8 *, u8 *, int, Word);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C6878(u8 *p, u8 *a, int a2);
extern int func_021C68A8(u8 *, u8 *, u8 *, u16);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern void func_021BFE60(u8 *, u8 *);
int func_021BF9A4(u8 *p, u8 *a, u8 *b, u16 *c);
int func_021BFA00(u8 *p, u8 *a, u8 *b, void *item);
int func_021BFA60(u8 *p, u8 *a, u8 *b, struct Q *q);
void func_021BFBD0(u8 *p, u32 fallback, u8 *record, u32 pos);
int func_021BFC08(u8 *p, u8 *q, u8 *d, u16 c);



int func_021BF9A4(u8 *p, u8 *a, u8 *b, u16 *c)
{
    int r;
    func_021D74F8(4929);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, *c);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x1c);
    r = func_021D775C(0x51);
    func_021D7540(4936);
    return r;
}




int func_021BFA00(u8 *p, u8 *a, u8 *b, void *item)
{
    int x;
    int y;
    if (func_021B8588(*(void ** *)&((struct Obj00003 *)p)->f4) == 2) {
        if (item != 0 && func_0201BEB8(item, 0xb) != 0) return 0;
        x = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, func_021D5440(a));
        y = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, func_021D5440(b));
        if (func_021B9A6C(x, y) == 0) return 1;
    }
    return 0;
}



/*
 * lever: Declare flag before base to place their spills at the original stack offsets.
 */
int func_021BFA60(u8 *p, u8 *a, u8 *b, struct Q *q)
{
    u8 flag;
    s8 x, y;
    int base;
    u32 scale;
    int v;
    u32 chance;
    if (func_021BF324(p, a, b)) return 1;
    if (func_021C69B8(p, a, (u32)b, q->h0)) return 1;
    if (func_021D62C4((struct Unk021D62A8 *)b, 32)) return 1;
    base = func_021C6A04(p, a, b, q);
    func_021D74F8(5014);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D7630(75, 0);
    func_021D75A8(39, func_021D59B4(a, 6));
    func_021D75A8(40, func_021D59B4(b, 7));
    func_021D7674(53, 4 << 10, 41, 4 << 15);
    func_021D70F0(p, 51);
    x = func_021D775C(39);
    y = func_021D775C(40);
    flag = func_021D775C(75);
    if ((func_021D62C4((struct Unk021D62A8 *)b, 17) && y > 6) || flag) y = 6;
    if (func_021D5BB0((struct UtilWork *)a, 14)) func_021D7704(53, 4915);
    scale = func_021D775C(53);
    func_021D7540(5039);
    v = x + 6 - y;
    if (v < 0) v = 0;
    if (v > 12) v = 12;
    chance = func_021D7B10(func_021D7908((u8)base, (u8)(s8)v), scale);
    if (chance > 100) chance = 100;
    if (func_021B911C(((struct Obj07752 *)p)->f4, 6)) chance = 100;
    if (func_021D78AC(100) < (u8)chance) return 1;
    return 0;
}



void func_021BFBD0(u8 *p, u32 fallback, u8 *record, u32 pos)
{
    u32 value = ((struct Obj05190 *)record)->f0;
    if (value == 0) value = fallback;
    func_021CD568(((struct Obj21062 *)p)->fC, (u16)pos, 0x30,
                 record[2], record[3], value, record[4]);
    record[4] = 0;
    record[5] |= 2;
}

/*
 * lever: Wide n/callee parameter avoids truncation; named one-word Word result supplies the frame word.
 */
int func_021BFC08(u8 *p, u8 *q, u8 *d, u16 c)
{
    int result;
    if (func_021D62C4((struct Unk021D62A8 *)q, 26) == 0) {
        int n = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, func_021D5440(q));
        if (func_021C66AC(p, q, (u32)d)) {
            func_021C5718(p, q, c);
            return 1;
        }
        if (func_021C6720(p, q, c) == 0) {
            if (func_021BFD24(p, q, n, d, c)) {
                Word s = func_021E896C(2, c);
                func_021C5C1C(p, q, 26, s);
            }
            return 2;
        }
        if (func_021BFD24(p, q, n, d, c) == 0) return 1;
        {
            u32 lock = func_021CC8D8(p + 0x1d74, 5124);
            func_021C6878(p, q, c);
            func_021CC95C((u32 *)(p + 0x1d74), lock, 5126);
        }
    }
    (*(u8 **)(p + 0x4a8))[4] = 1;
    {
        u32 lock = func_021CC8D8(p + 0x1d74, 5134);
        result = func_021C68A8(p, q, d, c);
        func_021CC95C((u32 *)(p + 0x1d74), lock, 5136);
    }
    func_021D5FC0((struct UtilWork *)q, 11);
    func_021BFE60(p, q);
    return result ? 4 : 3;
}
