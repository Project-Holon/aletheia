/*
 * function: func_021F98F8
 * address: 0x021F98F8
 * packet: pkt_ov186_021F98F8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 recoup. The old draft had the save and tag spill slots swapped
 *   (4 bytes). Declaring the heap parameter of func_0200B570 as u16 and keeping the
 *   tag as a plain u32 local `(heap & 0x7fff) | 0x8000` (no u16 cast) gives EXACT in
 *   c99 and c. Other forms tried: u16 or int tag, tag inline in the call, tag set
 *   before save, declaration order of tag and save, tag in the loop body, heap
 *   reassigned, u32 heap parameter, all six per-function pragmas: all 4 bytes off.
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_02045808 0x02045808 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0200B570 0x0200B570 thumb
 *   func_0200B910 0x0200B910 thumb
 *   func_0200D5D0 0x0200D5D0 thumb
 *   func_0200D6D0 0x0200D6D0 thumb
 *   func_0200D6EC 0x0200D6EC thumb
 *   func_0200B928 0x0200B928 thumb
 *   func_0200B98C 0x0200B98C thumb
 *   func_0200A5F8 0x0200A5F8 thumb
 *   func_0200A630 0x0200A630 thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Fields {u32 words[4];void *handles[4];u32 flags[4];u64 values[4];u32 state,ready;} Fields;
typedef unsigned char  u8;
struct Big;
struct Bits;
struct GdsProfile;
struct ObjC4;
struct RecGet;
struct U16Vec;
extern void *func_02012EBC(struct Big *p);
extern struct ObjC4 *func_0200B910(void);
extern u8 *func_0200B928(void);
extern void *func_0200A5F8(void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_02082BCC(void *,int,unsigned);
extern u32 func_0200B570(void *,u16,u32 *,u32);
extern void func_0200D5D0(struct GdsProfile *p, void *sys);
extern void *func_0200D6D0(const void *,u32);
extern u32 func_0200D6EC(struct RecGet *p);
extern u32 func_0200A630(struct Bits *p);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
void func_021F98F8(char *p, int skip, void *sys, int heap)
{
    int enabled=1;
    int i;
    u32 result;
    u32 save;
    void *profile;
    if(skip && *(int *)(p+0x54)) enabled=0;
    if(enabled) {
        u32 tag;
        save=(u32)func_02012EBC(sys);
        if(*(int *)(p+0x54)) {
            for(i=0;i<4;i++) {
                if(((Fields *)p)->handles[i]) {
                    func_02045808(((Fields *)p)->handles[i]);
                    ((Fields *)p)->handles[i]=0;
                }
            }
        }
        func_02082BCC(p,0,0x58);
        tag=(heap&0x7fff)|0x8000;
        for(i=0;i<4;i++) {
            func_0200B570((void *)save,tag,&result,i);
            if(result==1) {
                profile=func_0200B910();
                if(i==0) func_0200D5D0(profile,sys);
                *(int *)((u32)p+(u32)i*4)=1;
                *(void **)((u32)p+(u32)i*4+0x10)=func_0200D6D0(profile,0x59);
                *(u32 *)((u32)p+(u32)i*4+0x20)=func_0200D6EC(profile);
                *(u64 *)((u32)p+(u32)i*8+0x30)=func_0200B98C(func_0200B928(),4,0);
            }
        }
        *(u32 *)(p+0x50)=func_0200A630(func_0200A5F8(func_02012EBC(sys)));
        *(int *)(p+0x54)=1;
    }
}
