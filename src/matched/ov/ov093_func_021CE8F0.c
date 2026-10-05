/*
 * function: func_021CE8F0
 * address: 0x021CE8F0
 * packet: pkt_ov093_021CE8F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Six ordinary int offsets each receive 0x19a then 0x112;
 * a cached row pointer preserves their distinct stack homes and r5 base.
 * Reverse declarations and a full-word k local restore the spill order.
 * note 2026-10-05 (wave D9r lane 131): removed the 6 dead first assignments
 * (`invalid=0x19a;` before `invalid=0x112;`; `ok3=0x19a;` before
 * `ok3=0x112;` and 4 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021BA004 0x021BA004 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_0202A298 0x0202A298 thumb
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D7B60 0x021D7B60 thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   d_021EFF78 0x021EFF78 data ov093 a2
 */
#include "../include/Obj03689.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { OFFSET = 0x19a } Off;
struct Offsets { Off skip,ok0,ok1,ok2,ok3,invalid; };
static inline void init_offset(Off *value)
{
    *value = OFFSET;
    *value -= 0x88;
}
extern void *func_021B86B8(void ***);
struct Q1;
extern u8 func_021B904C(u8 *p, int k);
extern u16 func_021BA004(char *p, int i);
extern char *func_021B9AEC(char *,int);
extern u8 *func_021B990C(void *,u32,u8);
extern int func_021D5B68(void *);
extern int func_021B99B8(void *pp, unsigned int b);
extern u32 func_0202A298(u32,u32,u32);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D7B60(void *p, u32 b);
extern int func_021D5B48(u8 *p);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 func_021B9B98(char *);
extern const u16 d_021EFF78[4];
int func_021CE8F0(const u8 *p,u16 *out)
{
    u32 entry;
    int result;
    u32 count;
    u32 k;
    u32 key;
    u32 id, i;
    int a, b;
    u8 *mon;
    u8 *row;
    int skip,ok0,ok1,ok2,ok3,invalid;
    if ((u32)func_021B86B8(*(void *** *)&((struct Obj03689 *)p)->f0) != 1) goto fail;
    id = func_021B904C(((struct Obj03689 *)p)->f0,0);
    k = func_021BA004(((struct Obj03689 *)p)->f0,id);
    if (!k) goto fail;
    entry = (u32)func_021B9AEC(*(char * *)&((struct Obj03689 *)p)->f4,id);
    mon = func_021B990C(((struct Obj03689 *)p)->f4,id,0);
    if (func_021D5B68(mon)) {
        count = func_021B99B8(((struct Obj03689 *)p)->f0,id);
        for (i=1;i<count;i++) {
            mon = func_021B990C(((struct Obj03689 *)p)->f4,id,i);
            if (!func_021D5B68(mon)) break;
        }
    }
    result = -1;
    invalid=0x112;
    ok3=0x112;
    ok2=0x112;
    ok1=0x112;
    ok0=0x112;
    skip=0x112;
    for (i=0;i<4;i++) {
        row = (u8 *)p + i;
        if (!row[skip]) {
            key = d_021EFF78[i];
            if (func_0202A298(k,key,((struct Obj03689 *)p)->f19A)) {
                switch (key - 0x11) {
                case 1:
                    a = func_021D59B4(mon,13);
                    if ((u32)a <= func_021D7B60(mon,2)) { result = i; row[ok0] = 1; }
                    break;
                case 0:
                    if (!func_021D5B48(mon)) { result = i; row[ok1] = 1; }
                    break;
                case 2:
                    if (func_021B9B94((void *)entry) > 1 && func_021B9B98((char *)entry) == 1) { result = i; row[ok2] = 1; }
                    break;
                case 3:
                    if (func_021B9B94((void *)entry) > 1 && func_021B9B98((char *)entry) == 1) {
                        b = func_021D59B4(mon,13);
                        if ((u32)b <= func_021D7B60(mon,2)) { result = i; row[ok3] = 1; }
                    }
                    break;
                }
            } else row[invalid] = 1;
        }
    }
    if (result >= 0) { *out = d_021EFF78[result]; return 1; }
fail:
    return 0;
}
