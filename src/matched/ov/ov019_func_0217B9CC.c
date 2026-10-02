/*
 * function: func_0217B9CC
 * address: 0x0217B9CC
 * packet: pkt_ov019_0217B9CC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBA8 0x0200BBA8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 * Return from the legacy void tail forwarder 0200BAC8 is used by this caller.
 */
extern void *func_02012EBC(void *);
extern void *func_0200BAC8(void *);
extern unsigned int func_0200BBA8(void *);
extern void *func_0200BAF4(int, int);
void *func_0217B9CC(char *p)
{
    void *a;
    a = func_0200BAC8(func_02012EBC(*(void **)(*(char **)p + 8)));
    if (func_0200BBA8(a) == 0) return 0;
    return func_0200BAF4((int)a, 65);
}
