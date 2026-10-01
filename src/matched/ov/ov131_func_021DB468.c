/*
 * function: func_021DB468
 * address: 0x021DB468
 * packet: pkt_ov131_021DB468
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: repeat func_0204B3DC in both arms to retain branch to next.
 * symbols:
 *   func_021DBA54 0x021DBA54 thumb ov131
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DBA78 0x021DBA78 thumb ov131
 *   func_021D9EE8 0x021D9EE8 thumb ov131
 */
typedef unsigned char u8;
extern void func_021DBA54(u8 *,u8 *);
extern void func_0204B404(void *,u8 *,int);
extern void func_0204B3DC(void *,int);
extern void func_021DBA78(u8 *,int);
extern void func_021D9EE8(u8 *,u8 *);
void func_021DB468(u8 *a,u8 *b,u8 c,int d) {
    u8 box[4];
    if(a[28]==0) {
        func_021DBA54(b+176+c*24,box);
        func_0204B404(*(void **)(b+152),box,0);
        func_0204B3DC(*(void **)(b+152),0);
    } else func_0204B3DC(*(void **)(b+152),0);
    if(b[41]!=b[42] || *(int *)(b+20)==0) {
        if(b[41]!=255) func_021DBA78(b+176+b[41]*24,0);
    } else func_021DBA78(b+176+b[41]*24,2);
    func_021DBA78(b+176+c*24,1);
    if(b[41]!=c || d==1) {
        b[41]=c;
        func_021D9EE8(a,b);
    }
}
