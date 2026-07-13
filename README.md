Lung Image Binary Thresholding
A C program that applies a fixed-level thresholding algorithm to a 339x339 raw chest X-ray/scan to generate a binary mask.

Key Technologies
C (Standard Library)

Custom dip.h dynamic memory library

Methodology
The program processes the image pixel by pixel. If a pixel's intensity is strictly greater than the predefined threshold (t = 170), it is assigned a value of 255 (white); otherwise, it is assigned 0 (black). This isolates regions of high radiodensity.
