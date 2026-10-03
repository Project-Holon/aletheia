/*
 * function: func_021DB7C0
 * address: 0x021DB7C0
 * packet: pkt_ov175_021DB7C0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD044 0x021DD044 thumb ov175
 *   func_0203F028 0x0203F028 arm
 *   d_021E2F4C 0x021E2F4C data a4
 *   d_021E2F60 0x021E2F60 data a4
 *   d_021E2F7C 0x021E2F7C data a4
 *   d_021E2F70 0x021E2F70 data a4
 */
typedef unsigned long u32;
struct Field { const char *name; u32 type; u32 value; u32 pad; };
extern int func_021DD044(int);
extern int func_0203F028(const char *,const char *);
extern const char d_021E2F4C[],d_021E2F60[],d_021E2F7C[],d_021E2F70[];
void func_021DB7C0(int count,struct Field **fields,char *p,int n) {
    int i,j;
    struct Field *f;
    for(i=0;i<count;i++) {
        for(j=0;j<n;j++) {
            f=&fields[i][j];
            if(!func_0203F028(f->name,(const char *)func_021DD044(9))) *(u32 *)(p+0x40)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(10))) *(u32 *)(p+0x3c)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(12))) *(u32 *)(p+0x28)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(11))) *(u32 *)(p+0x24)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(13))) *(u32 *)(p+0x30)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(14))) *(u32 *)(p+0x2c)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(15))) *(u32 *)(p+0x48)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(16))) *(u32 *)(p+0x44)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(17))) *(u32 *)(p+0x38)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(18))) *(u32 *)(p+0x34)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(19))) *(u32 *)(p+0xc)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(20))) *(u32 *)p=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(21))) *(u32 *)(p+4)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(22))) *(u32 *)(p+0x10)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(23))) *(u32 *)(p+8)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(3))) *(u32 *)(p+0x20)=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(24))) *(u32 *)(p+0x18)=f->value;
            else if(!func_0203F028(f->name,d_021E2F4C)) *(u32 *)(p+0x4c)=f->value;
            else if(!func_0203F028(f->name,d_021E2F60)) *(u32 *)(p+0x50)=f->value;
            else if(!func_0203F028(f->name,d_021E2F7C)) *(u32 *)(p+0x54)=f->value;
            else if(!func_0203F028(f->name,d_021E2F70)) *(u32 *)(p+0x58)=f->value;
        }
    }
}
