/*
 * function: func_021E2A1C
 * address: 0x021E2A1C
 * packet: pkt_ov119_021E2A1C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DD2F4 0x021DD2F4 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_02028148 0x02028148 thumb
 *   func_02041B6C 0x02041B6C arm
 */
extern int func_0201C6B4(void *);
extern void func_0201C6EC(void *);
extern void func_0204B3DC(void *,int);
extern int func_021DD2F4(char *);
extern void func_021B6558(int,int,int);
extern void func_02028148(void *);
extern void func_02041B6C(int);
void func_021E2A1C(char *p,int a,int b) {
    if (!func_0201C6B4(*(void **)(p+0x740))) func_0201C6EC(*(void **)(p+0x740));
    if(a) func_0204B3DC(*(void **)(p+0xf04),1);
    if(b) func_021B6558(*(int *)(p+0x9c0),8,func_021DD2F4(p));
    if(*(void **)(p+0x648)) {
        func_02028148(*(void **)(p+0x648));
        *(void **)(p+0x648)=0;
        func_02041B6C(6);
    }
}
