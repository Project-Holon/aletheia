/*
 * function: func_021C08F8
 * address: 0x021C08F8
 * packet: pkt_ov099_021C08F8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum offset K274 with p+(off-delta) preserves register-offset
 *   stores; unparenthesized p+off-delta gave DIFF20/200.
 * prototype-evidence: C23B8 forwards the index to ov009 56860 and returns
 *   its address in r0; C23C8's final 0203C2B0 body returns the consumed bool.
 *   BDD48 retains the visibly loaded unused first input.
 * symbols:
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_0201AC80 0x0201AC80 thumb
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021C2810 0x021C2810 thumb ov099
 *   func_021BDE30 0x021BDE30 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { K274=0x274 } Off;
struct W;
struct S;
struct Work;
extern u8 func_021B97F4(struct W *);
extern u32 func_0201AC80(void *);
extern int func_021C23B8(int i);
extern u8 func_021BDD48(int, struct S *);
extern int func_021C27E0(struct S *);
extern int func_021C23C8(void *, void *);
extern void func_021C2810(struct S *, char *);
extern void func_021BDE30(void *, int, int);
extern void func_021C18C8(char *, int, int);
extern void func_021BA874(struct Work *, int);
extern void func_021BAADC(char *p, int a, int b);
extern void func_021BC090(void *);
extern void func_021BAAB8(char *, int, int);
int func_021C08F8(char *p)
{
    int n;
    int index;
    struct S *state;
    u32 kind;
    Off off = K274;
    n = func_021B97F4((struct W *)(p + off));
    *(u16 *)(p + (off - 0x32)) = n;
    if (n != 0) {
        func_0201AC80(*(void **)(p + 0xc8));
        index = n - 1;
        state = (struct S *)func_021C23B8(index);
        kind = func_021BDD48((int)p, state);
        func_021C27E0(state);
        if (kind == 6) return 0;
        if (func_021C23C8(p, (void *)-1)) {
            func_021C2810(*(struct S **)(p + 8), (char *)func_021C23B8(index));
            *(int *)(p + (off - 0xb0)) = 0xe10;
            func_021BDE30(p, 3, 3);
            func_021C18C8(p, 3, 3);
            func_021BA874((struct Work *)p, n - 1);
            *(u8 *)(p + 0x1351) = n;
            func_021BAADC(p, 14, 0);
            func_021BC090(p);
            *(int *)(p + (off - 0xa8)) = 0x88;
        } else {
            func_021BA874((struct Work *)p, n - 1);
            func_021BAAB8(p, 13, 0);
            *(int *)(p + (off - 0xa8)) = 0x15;
        }
    }
    return 1;
}
