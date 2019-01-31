EESchema Schematic File Version 4
LIBS:Battery Pack-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L EER:-BattTerminal BT2
U 1 1 5C4CA021
P 5250 4100
F 0 "BT2" H 5200 4300 50  0000 L CNN
F 1 "-BattTerminal" H 5050 4400 50  0000 L CNN
F 2 "EER:-Batt Terminal" H 5250 4300 50  0001 C CNN
F 3 "" H 5250 4300 50  0001 C CNN
F 4 "36-240-ND" H 5250 4100 50  0001 C CNN "Digikey"
	1    5250 4100
	1    0    0    -1  
$EndComp
$Comp
L EER:+BattTerminal BT1
U 1 1 5C4C9B3C
P 4500 4100
F 0 "BT1" H 4450 3900 50  0000 L CNN
F 1 "+BattTerminal" H 4250 3800 50  0000 L CNN
F 2 "EER:+Batt Terminal" H 4500 4300 50  0001 C CNN
F 3 "http://www.memoryprotectiondevices.com/datasheets/SN-T5-2-datasheet.pdf" H 4500 4300 50  0001 C CNN
F 4 "SN-T5-2-ND" H 4500 4100 50  0001 C CNN "Digikey"
	1    4500 4100
	-1   0    0    1   
$EndComp
Wire Wire Line
	5800 4100 5500 4100
Wire Wire Line
	7100 4100 6900 4100
$Comp
L EER:WirePad P1
U 1 1 5C4CAB37
P 2900 4250
F 0 "P1" H 3056 4715 50  0000 C CNN
F 1 "WirePad" H 3056 4624 50  0000 C CNN
F 2 "EER:Wire Pad" H 3000 4700 50  0001 C CNN
F 3 "" H 3000 4700 50  0001 C CNN
	1    2900 4250
	1    0    0    -1  
$EndComp
$Comp
L EER:-BattTerminal BT4
U 1 1 5C4CB272
P 6650 4100
F 0 "BT4" H 6600 4300 50  0000 L CNN
F 1 "-BattTerminal" H 6450 4400 50  0000 L CNN
F 2 "EER:-Batt Terminal" H 6650 4300 50  0001 C CNN
F 3 "" H 6650 4300 50  0001 C CNN
F 4 "36-240-ND" H 6650 4100 50  0001 C CNN "Digikey"
	1    6650 4100
	1    0    0    -1  
$EndComp
$Comp
L EER:+BattTerminal BT3
U 1 1 5C4CB6E8
P 6050 4100
F 0 "BT3" H 6000 3900 50  0000 L CNN
F 1 "+BattTerminal" H 5850 3800 50  0000 L CNN
F 2 "EER:+Batt Terminal" H 6050 4300 50  0001 C CNN
F 3 "http://www.memoryprotectiondevices.com/datasheets/SN-T5-2-datasheet.pdf" H 6050 4300 50  0001 C CNN
F 4 "SN-T5-2-ND" H 6050 4100 50  0001 C CNN "Digikey"
	1    6050 4100
	-1   0    0    1   
$EndComp
$Comp
L EER:+BattTerminal BT5
U 1 1 5C4CB990
P 7350 4100
F 0 "BT5" H 7300 3900 50  0000 L CNN
F 1 "+BattTerminal" H 7100 3800 50  0000 L CNN
F 2 "EER:+Batt Terminal" H 7350 4300 50  0001 C CNN
F 3 "http://www.memoryprotectiondevices.com/datasheets/SN-T5-2-datasheet.pdf" H 7350 4300 50  0001 C CNN
F 4 "SN-T5-2-ND" H 7350 4100 50  0001 C CNN "Digikey"
	1    7350 4100
	-1   0    0    1   
$EndComp
$Comp
L EER:-BattTerminal BT6
U 1 1 5C4CA4B3
P 8100 4100
F 0 "BT6" H 8050 4300 50  0000 L CNN
F 1 "-BattTerminal" H 7900 4400 50  0000 L CNN
F 2 "EER:-Batt Terminal" H 8100 4300 50  0001 C CNN
F 3 "" H 8100 4300 50  0001 C CNN
F 4 "36-240-ND" H 8100 4100 50  0001 C CNN "Digikey"
	1    8100 4100
	1    0    0    -1  
$EndComp
$Comp
L EER:WirePad P2
U 1 1 5C4CA92E
P 9450 3950
F 0 "P2" H 9606 4415 50  0000 C CNN
F 1 "WirePad" H 9606 4324 50  0000 C CNN
F 2 "EER:Wire Pad" H 9550 4400 50  0001 C CNN
F 3 "" H 9550 4400 50  0001 C CNN
	1    9450 3950
	-1   0    0    1   
$EndComp
$Comp
L EER:FuseHolder F1
U 1 1 5C4CEE3B
P 3500 4200
F 0 "F1" H 3750 4565 50  0000 C CNN
F 1 "FuseHolder" H 3750 4474 50  0000 C CNN
F 2 "EER:Glass Fuse Holder" H 3100 4550 50  0001 C CNN
F 3 "https://www.littelfuse.com/data/en/data_sheets/littelfuse_fuse-clips.pdf" H 3100 4550 50  0001 C CNN
F 4 "F4236-ND" H 3500 4200 50  0001 C CNN "Digikey"
	1    3500 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 4100 4250 4100
Wire Wire Line
	3400 4100 3200 4100
$Comp
L Device:Q_NMOS_DGS Q1
U 1 1 5C4D0B89
P 8750 4000
F 0 "Q1" V 9000 4000 50  0000 C CNN
F 1 "Q_NMOS_DGS" V 9091 4000 50  0000 C CNN
F 2 "Battery Pack:TRANS_DMN2020UFCL-7" H 8950 4100 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMN2020UFCL.pdf" H 8750 4000 50  0001 C CNN
F 4 "DMN2020UFCL-7DICT-ND" V 8750 4000 50  0001 C CNN "Digikey"
	1    8750 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	8350 4100 8450 4100
Wire Wire Line
	8950 4100 9150 4100
Wire Wire Line
	8750 3800 8750 3600
Wire Wire Line
	8450 4100 8450 3600
Wire Wire Line
	8450 3600 8500 3600
Connection ~ 8450 4100
Wire Wire Line
	8450 4100 8550 4100
$Comp
L Device:R_Small R1
U 1 1 5C4D119F
P 8600 3600
F 0 "R1" V 8404 3600 50  0000 C CNN
F 1 "100k" V 8495 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" H 8600 3600 50  0001 C CNN
F 3 "https://www.rohm.com/datasheet/ESR01MZPF/esr-e" H 8600 3600 50  0001 C CNN
F 4 "RHM100KKCT-ND" V 8600 3600 50  0001 C CNN "Digikey"
	1    8600 3600
	0    1    1    0   
$EndComp
Wire Wire Line
	8750 3600 8700 3600
Wire Wire Line
	8750 3600 8750 3150
Connection ~ 8750 3600
$Comp
L EER:WirePad P3
U 1 1 5C4D13AC
P 8600 2850
F 0 "P3" H 8756 3315 50  0000 C CNN
F 1 "WirePad" H 8756 3224 50  0000 C CNN
F 2 "EER:Small Wire Pad" H 8700 3300 50  0001 C CNN
F 3 "" H 8700 3300 50  0001 C CNN
	1    8600 2850
	0    1    1    0   
$EndComp
$EndSCHEMATC
