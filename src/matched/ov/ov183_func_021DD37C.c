/*
 * function: func_021DD37C
 * address: 0x021DD37C
 * packet: pkt_ov183_021DD37C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2 zero alignment bytes at 0x021DD3F6
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02025538 0x02025538 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021DDE2C 0x021DDE2C thumb ov183
 *   func_021DD5C8 0x021DD5C8 thumb ov183
 */
typedef unsigned short u16;
extern unsigned int func_021F9B9C(char *);
extern void *func_0203159C(void *, int, unsigned int);
extern void func_02082BCC(void *, int, unsigned int);
extern void *func_02025538(unsigned int a0, void *a1);
typedef unsigned int   u32;
extern u32 func_0201C440(void *p);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FBE54(char *, unsigned int, unsigned int);
extern void func_021DDE2C(char *, char *);
extern void func_021DD5C8(char *, char *);
int func_021DD37C(void *a, int unused, char *q)
{
    char *p = func_0203159C(a, 0x80, func_021F9B9C(*(char **)(q + 0xc)));
    func_02082BCC(p, 0, 0x80);
    *(u16 *)(p + 0x7c) = func_021F9B9C(*(char **)(q + 0xc));
    *(void **)p = func_02025538(*(u16 *)(p + 0x7c), *(void **)(q + 4));
    *(void **)(p + 4) = (void *)func_0201C440((void *)(*(u16 *)(p + 0x7c)));
    *(void **)(p + 0x74) = func_021FD760((unsigned int)(*(void **)(q + 4)), (char *)(*(int *)(q + 8)), 1, *(u16 *)(p + 0x7c));
    func_021FBE54(*(char **)(q + 8), 13, *(u16 *)(p + 0x7c));
    func_021DDE2C(p, q);
    func_021DD5C8(p, q);
    return 1;
}
