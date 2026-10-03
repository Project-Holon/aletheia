/*
 * function: func_021DAE1C
 * address: 0x021DAE1C
 * packet: pkt_ov121_021DAE1C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: The slot array at +0xa7c is the same layout as func_021DBC08;
 * its member access keeps the offset loaded before the loop index.
 * symbols:
 *   func_021DD980 0x021DD980 thumb ov121
 *   func_021DD1FC 0x021DD1FC thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_02040618 0x02040618 arm
 *   func_021DA2A8 0x021DA2A8 thumb ov121
 *   func_021DA280 0x021DA280 thumb ov121
 *   func_021DB528 0x021DB528 thumb ov121
 *   func_021DB3E8 0x021DB3E8 thumb ov121
 *   func_0200A348 0x0200A348 thumb
 *   func_021DBEE4 0x021DBEE4 thumb ov121
 *   func_020414EC 0x020414EC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021DA890 0x021DA890 thumb ov121
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned int u32;
typedef struct Obj { char pad[0xa7c]; char *slots[12]; } Obj;
extern void func_021DD980(char *);
extern void func_021DD1FC(void **);
typedef unsigned char  u8;
extern void func_021D9E04(u8 *p);
extern void func_02040618(u32,u32,u32);
extern void func_021DA2A8(u8 *p);
extern void func_021DA280(u8 *p);
extern void func_021DB528(char *,int);
extern void func_021DB3E8(char *);
extern u32 func_0200A348(struct Obj *);
extern void func_021DBEE4(void *);
extern void func_020414EC(u32);
extern void func_02041B6C(u32);
extern void func_021DA890(void *);
extern void func_020307B0(void *);
void func_021DAE1C(Obj *obj)
{
    char *p=(char *)obj;
    int i;
    u32 j;
    for(i=0;i<12;i++) {
        if(obj->slots[i]) {
            func_021DD980(obj->slots[i]);
            obj->slots[i]=0;
        }
    }
    func_021DD1FC(*(void ***)(p+0xab0));
    if(*(void **)(p+0xabc)) {
        func_021D9E04(*(void **)(p+0xabc));
        *(void **)(p+0xabc)=0;
    }
    func_02040618(3,0,0);
    func_02040618(2,0,0);
    func_021DA2A8(*(void **)(p+0xab8));
    func_021DA280(*(void **)(p+0xab8));
    func_021DB528(p,1);
    func_021DB528(p,0);
    func_021DB3E8(p);
    for(j=0;j<func_0200A348(*(void **)(p+0xc));j++)
        func_021DBEE4(p+0x28+j*0xdc);
    func_020414EC(4);
    func_020414EC(6);
    func_02041B6C(4);
    func_02041B6C(6);
    func_021DA890(*(void **)(p+0xac4));
    func_020307B0(p);
}
