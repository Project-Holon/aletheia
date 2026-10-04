/*
 * function: func_021D7EAC
 * address: 0x021D7EAC
 * packet: pkt_ov121_021D7EAC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE500 0x021DE500 thumb ov121
 *   func_021DE550 0x021DE550 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D6E3C 0x021D6E3C thumb ov121
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021D9288 0x021D9288 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021D6C28 0x021D6C28 thumb ov121
 *   func_021D6948 0x021D6948 thumb ov121
 *   func_021D96C4 0x021D96C4 thumb ov121
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0200A350 0x0200A350 thumb
 *   func_020312CC 0x020312CC arm
 *   func_021D9624 0x021D9624 thumb ov121
 *   func_021D6924 0x021D6924 thumb ov121
 *   func_021D9744 0x021D9744 thumb ov121
 *   func_021D6AEC 0x021D6AEC thumb ov121
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_0207D63C 0x0207D63C arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02005D90 0x02005D90 thumb
 *   func_021D73DC 0x021D73DC thumb ov121
 *   func_020307B0 0x020307B0 arm
 *   d_021DFB80 0x021DFB80 data a1
 *   d_021D6338 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021DE500(void *);
typedef signed int     s32;
extern void func_021DE550(char *p);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021D6E3C(void *task, u32 *state, u8 *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_021D9288(void *,int);
extern void func_021D9E04(u8 *p);
extern void func_021D6C28(u8 *p);
extern void func_021D6948(void *);
extern void func_021D96C4(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern int func_0200A350(void *);
extern void func_020312CC(u32,u32,u32);
extern u8 *func_021D9624(int arg, u16 heap);
extern void func_021D6924(u16 *p, u16 heap);
extern unsigned func_021D9744(char *p);
extern void func_021D6AEC(void *,void *,int);
extern void *func_021D9CA4(int,int,void *,void *,int);
extern void func_021D9FFC(u8 *p, int a, int b);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_0203D34C(u32,u32);
extern void func_02005D90(int,int);
extern void func_021D73DC(void *task, u32 *state, u8 *p);
extern void func_020307B0(void *);
extern const char d_021DFB80[];
extern const int d_021D6338[];
extern char ov115_id[];
void func_021D7EAC(void *task,u32 *state,u8 *p)
{
    int result;
    result=func_021DE500(*(void **)(p+944));
    switch(result) {
    case 1: case 2:
        func_021DE550(*(void **)(p+944));
        func_021DA8B0(task,(u32)func_021D6E3C);
        break;
    }
    switch(*state) {
    case 0:
        func_0204E720(3,0,16,0);
        *state=1; return;
    case 1:
        if(!func_0204E804()) {
            func_021D9288(p+312,0);
            *state=2; return;
        }
        break;
    case 2:
        if(*(void **)(p+644)) {
            func_021D9E04(*(void **)(p+644));
            *(void **)(p+644)=0;
        }
        func_021D6C28(p+660);
        func_021D6948(p+912);
        func_021D96C4(*(void **)(p+916));
        *(void **)(p+916)=0;
        *state=3; return;
    case 3:
        *(u8 **)(p+960)=func_02030734(29,40,0,d_021DFB80,2664);
        func_02082BCC(*(void **)(p+960),0,40);
        *(u32 *)(*(u8 **)(p+960))=*(u32 *)(p+952);
        *(u32 *)(*(u8 **)(p+960)+4)=0;
        *(u32 *)(*(u8 **)(p+960)+8)=1;
        *(u32 *)(*(u8 **)(p+960)+16)=0;
        *(u32 *)(*(u8 **)(p+960)+24)=0;
        *(u32 *)(*(u8 **)(p+960)+12)=9;
        if(!func_0200A350(*(void **)(p+956))) *(u32 *)(*(u8 **)(p+960)+20)=2;
        else *(u32 *)(*(u8 **)(p+960)+20)=0;
        func_020312CC((u32)ov115_id,(u32)d_021D6338,(u32)*(void **)(p+960));
        *state=5; return;
    case 5:
        *(void **)(p+916)=func_021D9624(1,29);
        func_021D6924((u16 *)(p+912),29);
        func_021D6AEC(p+660,(void *)func_021D9744(*(void **)(p+916)),29);
        *(void **)(p+644)=func_021D9CA4(1,15,*(void **)(p+924),*(void **)(p+920),29);
        func_021D9FFC(*(void **)(p+644),10,14);
        func_0207D63C((void *)0x04000050,4,24,15,3);
        func_0203D34C(1,29);
        func_02005D90(1154,65535);
        func_021D9288(p+312,1);
        *state=4; return;
    case 4:
        *state=6; return;
    case 6:
        func_0204E720(3,16,0,0);
        *state=7; return;
    case 7:
        if(!func_0204E804()) { *state=8; return; }
        break;
    case 8:
        if(!*(u32 *)(*(u8 **)(p+960)+28)) func_021DA8B0(task,(u32)func_021D73DC);
        else func_021DA8B0(task,(u32)func_021D6E3C);
        func_020307B0(*(void **)(p+960));
        break;
    }
}
