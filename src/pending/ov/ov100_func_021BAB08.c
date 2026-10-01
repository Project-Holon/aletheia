/*
 * function: func_021BAB08
 * address: 0x021BAB08
 * packet: pkt_ov100_021BAB08
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 veneer 0203D0C4 has no outside witness at +BC/+C6.
 *   Exact non-C body: E59FC000,E12FFF1C,0203DA68; unlabelled target.
 *   Data021BB83C resolves sole-ref on the byte-correct 256-byte run.
 *   D0C4 tail-forwards r0 unchanged; full DA68 body reads only that u32,
 *   copies it unchanged to singleton+74, no arithmetic or narrowing.
 *   scratch-only DA68 one --arm (no region), fixed flags: EXACT20, literal15.
 *   Verified C (not filed ARM9): extern unsigned char *g_021469F0;
 *   void func_0203DA68(unsigned int value) {
 *       *(unsigned int *)(g_021469F0+0x74)=value;
 *   }
 *   caller-only TU suggest-split MATCH256: two witnesses, both inside this
 *   sole function; zero viable pieces. Do not file overlay leaves while capped.
 * symbols:
 *   d_021BB83C 0x021BB83C data a4
 *   func_0203CBAC 0x0203CBAC arm
 *   func_0203D0C4 0x0203D0C4 arm
 *   func_0203D164 0x0203D164 arm
 *   func_0203D0AC 0x0203D0AC arm
 *   func_021BAAEC 0x021BAAEC thumb ov100
 *   func_021BA290 0x021BA290 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BAC80 0x021BAC80 thumb ov100
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Req {
    u32 first[24];
    u8 a,b,c,d,e,mode,f,kind;
    u32 word68;
    u16 value,limit;
};
extern const struct Req d_021BB83C;
extern void func_0203CBAC(struct Req *,u32,u32);
extern void func_0203D0C4(u32);
extern void func_0203D164(int);
extern void func_0203D0AC(int);
extern int func_021BAAEC(int,int);
extern void func_021BA290(int,int);
extern void func_021B95B8(u8 *,u32);
extern void func_021BAC80(int);
void func_021BAB08(int p)
{
    struct Req req;
    int zero,q;
    req=d_021BB83C;
    req.mode=4;
    switch(*(u32 *)(p+0x24c)) {
    case 1:case 2:case 3:case 4:
        req.kind=12;
        break;
    case 5:
        req.kind=38;
        req.a=4;
        break;
    case 7:
        req.kind=29;
        break;
    case 6:
        req.kind=28;
        break;
    case 11:
        req.kind=44;
        break;
    case 9:
        req.limit=17;
        req.kind=19;
        req.e=1;
        q=*(int *)(p+0x244);
        req.a=*(u8 *)(*(int *)(q+0x20)+0x60);
        req.b=*(u8 *)(*(int *)(q+0x20)+0x61);
        req.value=*(u16 *)(*(int *)(q+0x20)+0x6c);
        *(int *)(p+0xce8)=-1;
        break;
    case 10:
        req.limit=17;
        req.kind=18;
        req.e=1;
        q=*(int *)(p+0x244);
        req.a=*(u8 *)(*(int *)(q+0x20)+0x60);
        req.b=*(u8 *)(*(int *)(q+0x20)+0x61);
        req.value=*(u16 *)(*(int *)(q+0x20)+0x6c);
        *(int *)(p+0xce8)=-1;
        break;
    }
    zero=0;
    func_0203CBAC(&req,0,p);
    switch(*(int *)(p+0x24c)) {
    case 10:
        func_0203D0C4((u32)func_021BAAEC);
        func_0203D164(1);
        func_0203D0AC(17);
        break;
    case 9:
        func_0203D0C4((u32)func_021BAAEC);
        func_0203D164(zero);
        func_0203D0AC(17);
        break;
    case 5:
        func_0203D0AC(37);
        break;
    }
    func_021BA290(p,0);
    func_021B95B8((u8 *)p,(u32)func_021BAC80);
}
