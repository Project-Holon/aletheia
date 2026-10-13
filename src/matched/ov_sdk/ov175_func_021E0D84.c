/*
 * function: sciWsSubmitReportCustom
 * address:  0x021E0D84
 * packet:   pkt_021E0D84
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ghiPostAddFileFromMemory  0x021C24B4  arm  ov114
 *   sSciReportFileName    0x021E4370  data
 *   sSciReportContentType    0x021E4378  data
 *
 * Hand the +0x40/+0x44 pair of the source block to 0x021C24B4 together with
 * the 0x021E4370 and 0x021E4378 tables.
 */

typedef unsigned long u32;

struct GHIPost;
extern int ghiPostAddFileFromMemory(struct GHIPost *_post, char *name, char *buffer, int bufferLen, char *reportFilename, char *contentType);
extern u32 sSciReportFileName[];
extern u32 sSciReportContentType[];

void sciWsSubmitReportCustom(char *a, char *b)
{
    ghiPostAddFileFromMemory((struct GHIPost *)a, (char *)((u32)sSciReportFileName), (char *)(*(int *)(b + 0x40)), *(int *)(b + 0x44),
                  (char *)((u32)sSciReportFileName), (char *)((u32)sSciReportContentType));
}

