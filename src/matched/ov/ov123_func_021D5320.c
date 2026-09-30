/*
 * function: func_021D5320
 * address: 0x021D5320
 * packet: pkt_ov123_021D5320
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 * symbols:
 *   func_02012204 0x02012204 thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_020310C4 0x020310C4 arm
 *   func_02040618 0x02040618 arm
 *   func_0204A600 0x0204A600 arm
 */
extern void func_02027974(void *);
extern int func_0203CD98(void);
extern int func_0201058C(void *);
extern void func_020310C4(void *);
extern int func_0201C4E4(void *);
extern void func_02040618(int,int,int);
extern void func_0204A600(void);
extern int func_020121CC(void *);
extern int func_020221A4(void);
extern int func_02012204(const void *);
extern void func_0202223C(unsigned int,unsigned int);
int func_021D5320(int a,int b,int c,char *p)
{
    int result=1;
    if (*(void (**)(char *))p) {
        (*(void (**)(char *))p)(p);
        result=0;
    }
    if (*(void **)(p+0x238)) func_02027974(*(void **)(p+0x238));
    if (func_0203CD98()) {
        *(int *)(p+0x27c)=*(int *)(p+0x278);
        *(int *)(p+0x278)=func_0201058C(0);
    }
    func_020310C4(*(void **)(p+0x230));
    func_0201C4E4(*(void **)(p+0x234));
    func_02040618(4,3,*(int *)(p+0x268));
    --*(int *)(p+0x268);
    func_0204A600();
    if (!*(int *)(p+0x28c)) func_020121CC(*(void **)(p+0x264));
    if (func_020221A4() && func_02012204(*(void **)(p+0x264))) {
        *(int *)(p+8)=0;
        result=1;
        func_0202223C(0,0);
        func_0202223C(1,0);
    }
    return result;
}
