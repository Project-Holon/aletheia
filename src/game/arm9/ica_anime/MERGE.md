# ica_anime (arm9)

p01 is the whole TU. p02 (sub_02011292) and p03 (sub_020113D2) are alternate entries inside func_02011290 and func_020113D0 (same bytes, 2 bytes later). They overlap p01, so they cannot be merged; gamecheck still wants them defined. Leave as separate files.