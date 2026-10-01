/*
 * function: func_021B96E0
 * address: 0x021B96E0
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B96E0
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   callbacks 0x021BC84C data a4
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BAF30 0x021BAF30 thumb ov223
 *   func_021BC4F4 0x021BC4F4 thumb ov223
 *   func_021BC508 0x021BC508 thumb ov223
 *   func_021B97F8 0x021B97F8 thumb ov223
 *   func_021BC514 0x021BC514 thumb ov223
 */
extern int (*callbacks[])(char *,int *);
extern void func_0201C4E4(void *);
extern void func_021BAF30(int *);
extern void func_021BC4F4(char *);
extern void func_021BC508(void *);
extern void func_021B97F8(void *);
extern void func_021BC514(void *);
int func_021B96E0(void *a,int *state,void *b,char *p)
{
    int old=*state;
    *state=callbacks[*state](p,(int *)(p+12));
    if(*state!=13) {
        if(*state!=old) *(int *)(p+12)=0;
    } else return 1;
    if(*state>=2&&*state<=11) {
        func_0201C4E4(*(void **)(p+28));
        func_021BAF30((int *)p);
        func_021BC4F4(*(char **)(p+20));
        func_021BC508(*(void **)(p+20));
        func_021B97F8(p);
        func_021BC514(*(void **)(p+20));
    }
    return 0;
}
