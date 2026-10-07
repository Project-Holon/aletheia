/*
 * file:     pdw_postman_p02.c
 * unit:     yes
 * function: func_021B76B4, func_021B76F8
 * address:  0x021B76B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201292C  0x0201292C  thumb
 *   func_02009310  0x02009310  thumb
 *   func_02009330  0x02009330  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02009364  0x02009364  thumb
 *   func_02007E3C  0x02007E3C  thumb
 */
struct BigObj;
struct Sub02009210Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

void *func_0201292C(const struct BigObj *p);
u16 func_02009310(const struct Sub02009210Obj *obj, int i);
u8 func_02009330(const struct Sub02009210Obj *obj, int i);
int func_02007E50(void *saved, int a, int b, int c);
void func_02009364(struct Sub02009210Obj *obj, int i);
extern int func_02007E3C(void *ctx, void *a, int b, int key);
void func_021B76B4(void *a0, int a1, int a2);
int func_021B76F8(void *p, int key, void *q);


/*
 * Iterates 0x14 slots of a container, matching each non-null entry through a
 * four-argument predicate and releasing the ones it accepts.
 */
void func_021B76B4(void *a0, int a1, int a2)
{
    void *saved = func_0201292C(a0);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        int r6 = func_02009310((const struct Sub02009210Obj *)a2, i);
        int r2 = func_02009330((const struct Sub02009210Obj *)a2, i);
        if (r6 != 0) {
            if (func_02007E50(saved, r6, r2, a1) == 1)
                func_02009364((struct Sub02009210Obj *)a2, i);
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
int func_021B76F8(void *p, int key, void *q)
{
    void *ctx;
    u32 i;
    int n;
    void *a;
    int b;

    ctx = func_0201292C(p);
    i = 0;
    n = 0;
    for (; i < 0x14; i++) {
        a = (void *)func_02009310(q, i);
        b = func_02009330(q, i);
        if (a != 0) {
            if (func_02007E3C(ctx, a, b, key) == 0)
                n++;
        }
    }
    return n;
}
