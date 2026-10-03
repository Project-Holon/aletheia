/*
 * function: func_021B9B64
 * address: 0x021B9B64
 * packet: pkt_ov220_021B9B64
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 021B9B88 stores count byte, 021B9B8E immediately rereads it; only that reread is volatile.
 * prototype: 0204B294 original caller stores its live r0 return as actor despite owning void declaration.
 * symbols:
 * func_020490F4 0x020490F4 arm
 * func_0204AC18 0x0204AC18 arm
 * func_0204A6C8 0x0204A6C8 arm
 * func_0204AF28 0x0204AF28 arm
 * func_02049238 0x02049238 arm
 * func_02082BCC 0x02082BCC arm
 * func_021BA1E0 0x021BA1E0 thumb ov220
 * func_0204B294 0x0204B294 arm
 * func_0204B878 0x0204B878 arm
 * func_0204B92C 0x0204B92C arm
 * table 0x021BA3AC data ov220 a1
 * coords 0x021BA338 data ov220 a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Param {s16 x,y;u32 zero;};
extern const u8 table[],coords[];
extern void *func_020490F4(u32,u16);
extern int func_0204AC18(void*,u32,u32,u32,u16,u16,u16),func_0204A6C8(void*,u32,u32,u32,u16),func_0204AF28(void*,u32,u32,u32);
extern void func_02049238(void*),func_02082BCC(void*,u32,u32);
extern u32 func_021BA1E0(u8 *p);
extern void *func_0204B294(u32,u32,u32,u32,u32,u16,u16);
extern void func_0204B878(void*,u16),func_0204B92C(void*,u32);
void func_021B9B64(char *p)
{
    void *owner;
    struct Param param;
    u8 i=0;
    *(u8*)(p+0x84)=0;
    if(*(u32*)(p+0xb0)!=7){
        *(u8*)(p+0x84)=*(const u8*)((u32)table+*(u32*)(p+0xb0)*12);
        if(*(volatile u8*)(p+0x84)){
            owner=func_020490F4(201,*(u16*)p);
            *(int*)(p+0x8c)=func_0204AC18(owner,1,0,0,0,1,*(u16*)p);
            *(int*)(p+0x88)=func_0204A6C8(owner,3,0,0,*(u16*)p);
            *(int*)(p+0x90)=func_0204AF28(owner,6,7,*(u16*)p);
            func_02049238(owner);
            func_02082BCC(&param,0,8);
            for(;i<*(u8*)(p+0x84);i++){
                param.x=*(const s16*)((u32)coords+(u32)i*4);
                param.y=*(const s16*)((u32)coords+(u32)i*4+2);
                *(void**)((u32)p+(u32)i*4+0x94)=func_0204B294(func_021BA1E0(*(void**)(p+8)),*(u32*)(p+0x88),*(u32*)(p+0x8c),*(u32*)(p+0x90),(u32)&param,0,*(u16*)p);
                func_0204B878(*(void**)((u32)p+(u32)i*4+0x94),0);
                func_0204B92C(*(void**)((u32)p+(u32)i*4+0x94),1);
            }
        }
    }
}
