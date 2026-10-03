/*
 * function: func_021BA878
 * address: 0x021BA878
 * packet: pkt_ov093_021BA878
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB964 0x021BB964 thumb ov093
 *   func_021C8138 0x021C8138 thumb ov093
 *   func_021C8140 0x021C8140 thumb ov093
 *   func_021C7CBC 0x021C7CBC thumb ov093
 *   func_021C7CC8 0x021C7CC8 thumb ov093
 *   func_021C7CD4 0x021C7CD4 thumb ov093
 *   func_021C7CDC 0x021C7CDC thumb ov093
 *   func_021C7CE8 0x021C7CE8 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D54B4 0x021D54B4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021BB964(void *);
extern int func_021C8138(void *);
extern u8 func_021C8140(void *, int);
extern u16 func_021C7CBC(void *);
extern u16 func_021C7CC8(void *);
extern u16 func_021C7CD4(void *);
extern u16 func_021C7CDC(void *);
extern u16 func_021C7CE8(void *);
extern char *func_021B9AEC(char *, int);
extern u32 func_021B9B94(void *);
extern u8 func_021B9B98(char *);
extern void *func_021B9BF0(void *, u8);
extern u8 func_021D54B4(void *);
extern int func_021D59B4(u8 *p, int k);
extern int func_021B8B9C(void *, u8);

void func_021BA878(u8 *p)
{
    u8 *q;
    u8 *a;
    char *list;
    u32 n;
    u32 count;
    u32 i;
    void *item;
    if (*(void **)(p + 8) == 0)
        return;
    a = func_021BB964(*(void **)(p + 8));
    q = *(u8 **)p;
    q[0xb6] = func_021C8138(a);
    q[0xb7] = func_021C8140(a, 0);
    q[0xb8] = func_021C7CBC(a);
    q[0xb9] = func_021C7CC8(a);
    q[0xba] = func_021C7CD4(a);
    q[0xbb] = func_021C7CDC(a);
    q[0xbc] = func_021C7CE8(a);
    if (*(int *)(q + 0x8c) == 1)
        q[0xbd] = 1;
    list = func_021B9AEC((char *)p + 0x1b0, 0);
    n = func_021B9B94(list);
    count = func_021B9B98(list);
    for (i = 0; i < n; i++) {
        item = func_021B9BF0(list, i);
        q[0xc0] += func_021D54B4(item);
        *(u16 *)(q + 0xb4) += (u16)func_021D59B4(item, 13);
    }
    q[0xbf] = n - count;
    list = func_021B9AEC((char *)p + 0x1b0, 1);
    n = func_021B9B94(list);
    count = func_021B9B98(list);
    q[0xbe] = n - count;
    if (func_021B8B9C(p, 3)) {
        list = func_021B9AEC((char *)p + 0x1b0, 3);
        if (list) {
            n = func_021B9B94(list);
            count = func_021B9B98(list);
            q[0xbe] += (u8)(n - count);
        }
    }
}
