/*
 * function: func_021BBB0C
 * address: 0x021BBB0C
 * packet: pkt_ov225_021BBB0C
 * status: EXACT*
 * region: ov225
 * isa: thumb
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * trailing: 021BBBF0 callback already owns separate verified shard; BF2 alignment.
 * symbols:
 *   func_021BBCF4 0x021BBCF4 thumb ov225
 *   func_021BBC50 0x021BBC50 thumb ov225
 *   func_021BBD28 0x021BBD28 thumb ov225
 *   func_021B9FBC 0x021B9FBC thumb ov225
 *   func_021BA158 0x021BA158 thumb ov225
 *   func_021BBD74 0x021BBD74 thumb ov225
 *   func_021BA154 0x021BA154 thumb ov225
 *   func_021BA0F0 0x021BA0F0 thumb ov225
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BBCF4(char *);
extern void func_021BBC50(char *);
extern void func_021BBD28(u8 *);
extern void func_021B9FBC(char *);
extern int func_021BA158(char *);
extern int func_021BA154(char *);
extern void func_021BBD74(char *);
extern void func_021BA0F0(char *,unsigned,unsigned);
int func_021BBB0C(char *p)
{
    int result = 0;
    int timer = *(signed char *)(p + 0x3c);
    int choice;
    if (timer == 0) result = 1;
    else if (timer > 0) {
        if (timer == 1) {
            func_021BBCF4(p);
            func_021BBC50(p);
        }
        *(signed char *)(p + 0x3c) -= 1;
    }
    if (*(u32 *)(p + 0x38) != 1) func_021BBD28((u8 *)p);
    if (*(u32 *)(p + 0x38) == 0 || *(u32 *)(p + 0x38) == 2) {
        func_021B9FBC(*(char **)(*(char **)(p + 4) + 0x34));
        if (*(u32 *)(p + 0x38) == 0) {
            choice = func_021BA158(*(char **)(*(char **)(p + 4) + 0x34));
            if (choice == -1) goto done;
            *(u32 *)(p + 0x38) = 2;
            if (choice == 4) {
                if (*(u8 *)(p + 8) != 0) {
                    *(u8 *)(p + 8) -= 1;
                    *(u32 *)(p + 0xc) = 1;
                }
            } else if (choice == 5) {
                if (*(u8 *)(p + 8) < *(u8 *)*(char **)p - 1) {
                    *(u8 *)(p + 8) += 1;
                    *(u32 *)(p + 0xc) = 1;
                }
            }
            if (*(u32 *)(p + 0xc)) func_021BBD74(p);
        } else {
            choice = func_021BA154(*(char **)(*(char **)(p + 4) + 0x34));
            if (choice == -1) goto done;
            switch (choice) {
            case 1:
                *(u32 *)(*(char **)p + 0x28) = 0;
                *(u32 *)(p + 0x38) = 1;
                *(signed char *)(p + 0x3c) = 1;
                break;
            case 4: case 5:
                *(u32 *)(p + 0x38) = 0;
                if (*(u32 *)(p + 0xc)) {
                    func_021BA0F0(*(char **)(*(char **)(p + 4) + 0x34), *(u8 *)*(char **)p, *(u8 *)(p + 8));
                    *(u32 *)(p + 0xc) = 0;
                }
                break;
            }
        }
    }
done:
    return result;
}
