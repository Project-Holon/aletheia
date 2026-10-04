/*
 * function: func_021DCCE4
 * address: 0x021DCCE4
 * packet: pkt_ov121_021DCCE4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: separate case-1 guard tests preserve the branch to the shared state store; a short-circuit guard gives DIFF404.
 * symbols:
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021D9E50 0x021D9E50 thumb ov121
 *   func_021DA038 0x021DA038 thumb ov121
 *   func_021DA148 0x021DA148 thumb ov121
 *   func_021DA178 0x021DA178 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021DA8B8 0x021DA8B8 thumb ov121
 *   func_021DC08C 0x021DC08C thumb ov121
 *   func_021DE014 0x021DE014 thumb ov121
 *   func_0200A0C8 0x0200A0C8 thumb
 *   func_0200A2B8 0x0200A2B8 thumb
 *   func_0200A2D8 0x0200A2D8 thumb
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 v[7];u16 a,b,c,d;} Desc;
extern void *func_021D9CA4(int,int,void *,void *,int);
typedef unsigned char  u8;
extern void func_021D9FFC(u8 *p, int a, int b);
extern void func_021D9F08(u8 *a, int b, int c, int d);
extern unsigned func_021D9FF8(u8 *p);
extern void func_021D9E04(u8 *p);
extern void func_021D9E50(u8 *p);
extern void *func_021DA038(const void *,u16);
extern void func_021DA148(u8 *p);
extern int func_021DA178(char *p);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021DA8B8(u32 *p);
extern void func_021DC08C(void *task, u32 *state, char *p);
extern int func_021DE014(char *p);
extern u32 func_0200A0C8(u8 *p);
extern void func_0200A2B8(void *a0, int a1);
extern int func_0200A2D8(void *a0, int a1);
extern void func_02082BCC(void *,int,int);
void func_021DCCE4(void *arg,u32 *state,char *p)
{
    Desc d;
    int result;
    int ready;
    switch (*state) {
    case 0:
        *state=1;
        break;
    case 1:
        if (!*(u32 *)p) *state=5;
        else if (func_0200A0C8(*(void **)(p+12))) *state=5;
        else *state=2;
        break;
    case 2:
        if (!*(void **)(p+0xabc)) {
            *(void **)(p+0xabc)=func_021D9CA4(0,15,*(void **)(p+20),*(void **)(p+16),29);
            func_021D9FFC(*(void **)(p+0xabc),1,13);
        }
        func_021D9F08(*(void **)(p+0xabc),*(int *)(p+28),93,1);
        *state=3;
        break;
    case 3:
        if (func_021D9FF8(*(void **)(p+0xabc))) {
            func_02082BCC(&d,0,36);
            d.v[0]=*(u32 *)(p+28);
            d.v[1]=*(u32 *)(p+16);
            d.v[2]=*(u32 *)(p+20);
            d.v[3]=124;
            d.v[4]=125;
            d.v[6]=2;
            d.a=0; d.b=15; d.c=13; d.d=1;
            *(void **)(p+0xac0)=func_021DA038(&d,*(u16 *)(p+36));
            *state=4;
        }
        break;
    case 4:
        result=func_021DA178(*(void **)(p+0xac0));
        *(u16 *)(p+0xbac)=0x7fff;
        if (result!=-1) {
            func_021DA148(*(void **)(p+0xac0));
            *(void **)(p+0xac0)=0;
            if (!result) *state=5;
            else {
                if (*(void **)(p+0xabc)) {
                    func_021D9E04(*(void **)(p+0xabc));
                    *(void **)(p+0xabc)=0;
                }
                func_021DA8B0(arg,(u32)func_021DC08C);
            }
        }
        break;
    case 5:
        if (*(void **)(p+0xad4)) *state=6;
        else *state=10;
        break;
    case 6:
        if (!*(void **)(p+0xabc)) {
            *(void **)(p+0xabc)=func_021D9CA4(0,15,*(void **)(p+20),*(void **)(p+16),29);
            func_021D9FFC(*(void **)(p+0xabc),1,13);
        }
        func_021D9F08(*(void **)(p+0xabc),*(int *)(p+28),115,2);
        *state=7;
        break;
    case 7:
        if (func_021D9FF8(*(void **)(p+0xabc))) *state=8;
        break;
    case 8:
        ready=1;
        if (*(void **)(p+0xaac) && !func_021DE014(*(void **)(p+0xaac))) ready=0;
        if (ready) {
            func_0200A2B8(*(void **)(p+12),(int)(*(void **)(p+32)));
            *state=9;
        }
        break;
    case 9:
        if (func_0200A2D8(*(void **)(p+12),(int)(*(void **)(p+32)))==2) *state=10;
        break;
    case 10:
        if (*(void **)(p+0xabc)) {
            func_021D9E04(*(void **)(p+0xabc));
            *(void **)(p+0xabc)=0;
        }
        func_021DA8B8(arg);
        break;
    }
    if (*(void **)(p+0xabc)) func_021D9E50(*(void **)(p+0xabc));
}
