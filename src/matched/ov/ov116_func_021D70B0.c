/*
 * function: WIFI_BSUBWAY_IsUploadDone
 * address: 0x021D70B0
 * packet: pkt_ov116_021D70B0
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFI_BSUBWAY_PollAsync 0x021D70EC thumb ov116
 *   WIFI_BSUBWAY_AsyncHasError 0x021D7158 thumb ov116
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int WIFI_BSUBWAY_PollAsync(u8 *, int *);
extern int WIFI_BSUBWAY_AsyncHasError(u8 *);
int WIFI_BSUBWAY_IsUploadDone(void *unused, u8 *p)
{
    int result;
    if (WIFI_BSUBWAY_PollAsync(p, &result) && WIFI_BSUBWAY_AsyncHasError(p) == 0) return 1;
    return 0;
}
