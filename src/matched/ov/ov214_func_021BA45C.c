/*
 * function: func_021BA45C
 * address: 0x021BA45C
 * packet: pkt_ov214_021BA45C
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: BA794's third argument is narrowed at 021BA49A..A0; caller
 * extern uses u16 despite its own source's unsigned parameter.
 * symbols:
 *   func_02035630 0x02035630 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021BA794 0x021BA794 thumb ov214
 *   func_021BA6F0 0x021BA6F0 thumb ov214
 */
typedef unsigned short u16;
typedef struct {int a,b,c;} Obj;
extern int func_02035630(void);
extern void func_021BA794(Obj*,char*,u16);
extern void func_021BA6F0(Obj*,char*);
void func_021BA45C(Obj*obj,char*p)
{
    unsigned threshold;
    if(func_02035630()==30)threshold=30;else threshold=60;
    if(obj->c && !*(int*)(p+0xb4) && (*(unsigned*)(p+0xac)>=threshold || *(int*)(p+0xb0))){
        func_021BA794(obj,p,*(unsigned*)(p+0xac)/threshold);
        if(*(unsigned*)(p+0xac)>=threshold){
            --*(unsigned*)(p+0xac);
            if(*(unsigned*)(p+0xac)==threshold-1)*(int*)(p+0xb8)=1;
        }else{
            --*(unsigned*)(p+0xb0);
            if(!*(unsigned*)(p+0xb0))func_021BA6F0(obj,p);
        }
    }
}
