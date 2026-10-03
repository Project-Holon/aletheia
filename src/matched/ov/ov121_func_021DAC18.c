/*
 * function: func_021DAC18
 * address: 0x021DAC18
 * packet: pkt_ov121_021DAC18
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02082A7C 0x02082A7C arm
 *   func_0203084C 0x0203084C arm
 *   func_02040618 0x02040618 arm
 *   func_021DBDF4 0x021DBDF4 thumb ov121
 *   func_021DA854 0x021DA854 thumb ov121
 *   func_021DB018 0x021DB018 thumb ov121
 *   func_021DB478 0x021DB478 thumb ov121
 *   func_021DA1BC 0x021DA1BC thumb ov121
 *   func_021DCFC8 0x021DCFC8 thumb ov121
 *   func_021DBDBC 0x021DBDBC thumb ov121
 *   func_021DBF04 0x021DBF04 thumb ov121
 *   func_021DC02C 0x021DC02C thumb ov121
 *   func_021DD24C 0x021DD24C thumb ov121
 *   func_021DE0AC 0x021DE0AC thumb ov121
 *   func_021DC08C 0x021DC08C thumb ov121
 *   func_021DCEC4 0x021DCEC4 thumb ov121
 *   d_021DFBB0 0x021DFBB0 data a4
 *   d_021DF8FC 0x021DF8FC data a4
 *   d_021DF890 0x021DF890 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 w[9];} Input;
typedef struct {u32 w[51];} Record;
typedef struct {u32 w[12];} Desc;
extern char d_021DFBB0[],d_021DF8FC[],d_021DF890[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void func_02082A7C(int,void *,int);
extern void *func_0203084C(u32 heapId);
extern void func_02040618(u32,u32,u32);
extern u32 func_0200A348(void *);
extern u32 func_0200A0E4(u8 *p, u32 a);
extern int func_0200A000(char *p, int idx, void *buf);
extern void func_021DBDF4(char *,const Record *,char *,u16);
extern void *func_021DA854(void *,void *,u16);
extern void func_021DB018(char *,u16);
extern void func_021DB478(char *,int,int,int,u16);
extern void *func_021DA1BC(void *,const char *,u32,u16,u16,u32,u32,int,u16);
extern void *func_021DCFC8(const Desc *,u16);
extern int func_021DBDBC(void *);
extern int func_021DBF04(void *);
extern char *func_021DC02C(void *);
extern void *func_021DD24C(void *,void *,void *,u16);
extern void func_021DE0AC(u8 *p, u32 b);
extern void func_021DC08C(void *task, u32 *state, char *p);
extern void func_021DCEC4(void *arg, int *state, char *p);
char *func_021DAC18(const Input *src,u16 heap)
{
    char *out;
    int count=0;
    u32 i;
    int j;
    Desc d;
    Record record;
    const char *table;
    int n;
    void *callback;
    out=func_02030734(heap,0xc70,0,d_021DFBB0,0x19f);
    func_02082BCC(out,0,0xc70);
    *(int *)(out+0xad0)=1;
    *(Input *)out=*src;
    *(u16 *)(out+36)=heap;
    func_02082A7C(-1,out+0xb48,32);
    func_02082A7C(-1,out+0xb88,32);
    func_02082A7C(-1,out+0xb68,32);
    for(i=0;i<func_0200A348(*(void **)(out+12));i++) {
        if(func_0200A0E4(*(void **)(out+12),i)) {
            count++;
            func_0200A000(*(void **)(out+12),i,&record);
            func_021DBDF4(out+40+i*0xdc,&record,out,heap);
        }
    }
    callback=(void *)func_021DC08C;
    if(*(int *)out) callback=(void *)func_021DCEC4;
    *(void **)(out+0xac4)=func_021DA854(out,callback,heap);
    func_021DB018(out,heap);
    func_021DB478(out,1,0,*(int *)(out+0xac8),heap);
    if(count) {table=d_021DF8FC;n=3;}
    else {table=d_021DF890;n=2;}
    *(void **)(out+0xab8)=func_021DA1BC(0,table,n,1,3,*(u32 *)(out+20),*(u32 *)(out+28),*(int *)(out+16),heap);
    func_02082BCC(&d,0,48);
    d.w[0]=6;d.w[1]=4;d.w[2]=14;d.w[3]=15;d.w[4]=11;d.w[5]=14;
    d.w[6]=*(u32 *)(out+8);d.w[7]=*(u32 *)(out+12);d.w[8]=*(u32 *)(out+28);
    d.w[9]=*(u32 *)(out+16);d.w[10]=*(u32 *)(out+20);d.w[11]=*(u32 *)(out+24);
    *(void **)(out+0xab0)=func_021DCFC8(&d,heap);
    if(func_021DBDBC(out)) {
        for(j=0;j<12;j++) {
            if(func_021DBF04(out+40+j*0xdc))
                *(void **)(out+0xa7c+j*4)=func_021DD24C(func_021DC02C(out+40+j*0xdc),*(void **)(out+0xab0),(void *)src->w[8],heap);
        }
        func_021DE0AC(*(void **)(out+0xa7c),0);
        func_0203084C(29);
    }
    func_02040618(3,3,0);
    func_02040618(7,3,0);
    return out;
}


