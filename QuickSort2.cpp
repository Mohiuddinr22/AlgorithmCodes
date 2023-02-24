#include <iostream>
using namespace std;

bool IfSorted(int *array, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        if (array[i] > array[i + 1])
            return false;
        if (array[size - 1] < array[size - 2])
            return false;
        if (array[i] > array[i + 1])
            return false;
        i++;
    }
    return true;
}

void DisplayArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << "\t";

    cout << endl;
    if (IfSorted(array, 10))
        cout << "Your array is sorted" << endl;
    else
        cout << "Your array is not sorted" << endl;
}

int Partition(int *array, int low, int high, int pivot)
{
    int left = low, right = high;
    while (left < right)
    {
        while (array[left] <= pivot)
            left++;
        while (array[right] > pivot)
            right--;
        if (left < right)
            swap(array[left], array[right]);
    }
    swap(array[low], array[right]);
    return right;
}

void QuickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = array[low];
        int pivotIndex = Partition(array, low, high, pivot);
        QuickSort(array, low, pivotIndex - 1);
        QuickSort(array, pivotIndex + 1, high);
    }
}

int main()
{
    int bigArray[3000] = {4436, 9297, 9589, 1367, 5724, 9132, 2501, 7400, 3161, 8793, 8416, 1382, 6412, 7293, 1701, 1540, 8923, 7557, 4406, 1599, 8190, 9381, 8502, 3667, 2065, 9400, 7923, 1381, 4065, 8423, 7797, 5284, 2331, 3542, 8952, 6015, 4734, 1934, 9361, 9757, 9071, 3868, 7119, 1991, 3259, 4399, 5279, 2682, 8344, 6010, 4675, 1086, 9882, 6326, 9126, 2081, 7013, 4640, 4750, 8779, 1846, 3878, 6096, 5846, 2224, 5976, 6266, 6995, 5588, 2025, 3043, 2592, 6821, 1465, 1687, 7241, 8683, 4369, 7377, 2367, 4739, 1905, 9184, 5934, 8566, 5371, 6917, 9705, 7408, 5783, 1644, 6517, 4593, 1901, 7099, 6942, 2477, 4001, 6891, 2783, 3886, 4340, 3910, 3028, 7622, 2383, 5772, 8482, 3522, 6752, 8946, 7854, 4384, 4899, 8895, 1232, 3085, 3744, 6608, 8201, 4489, 9574, 9742, 4715, 7566, 4139, 5896, 9491, 7002, 1483, 9963, 7488, 5088, 5212, 3560, 7305, 2215, 6935, 1028, 7606, 2290, 3426, 4323, 4848, 3292, 1959, 7993, 5651, 6476, 9141, 8197, 9941, 4990, 4696, 3718, 8867, 9843, 4468, 7222, 8354, 5297, 7170, 7313, 4499, 4891, 8486, 3304, 3630, 4443, 2585, 1941, 4768, 3316, 5635, 9616, 1966, 9380, 5926, 1734, 1630, 1105, 1306, 8872, 7522, 9504, 9201, 5453, 3312, 4889, 6251, 6845, 5339, 3318, 5685, 4330, 3804, 6348, 1788, 5849, 2171, 2934, 8511, 7462, 5963, 7799, 1425, 6937, 4717, 7070, 7616, 6196, 2218, 5492, 9500, 9250, 5630, 6716, 8302, 4838, 1826, 6893, 7653, 2397, 4692, 2235, 1182, 2805, 4165, 7963, 3990, 3022, 1500, 2830, 2714, 2895, 9452, 2518, 4946, 6050, 2656, 3173, 6536, 2151, 7834, 2033, 7265, 1396, 2056, 9788, 2365, 8364, 4393, 6772, 6209, 4306, 8831, 2249, 3941, 1803, 9660, 1053, 5671, 6687, 5812, 5567, 8828, 5996, 7967, 4580, 9962, 3413, 6363, 1923, 1530, 1450, 7841, 7484, 9973, 1448, 9331, 9404, 1177, 1272, 2697, 1567, 9781, 9860, 8744, 4046, 9908, 5105, 3811, 2733, 2338, 2561, 4616, 8612, 4256, 7457, 8051, 6141, 5502, 3711, 9438, 2077, 2838, 8958, 2812, 7105, 2929, 5138, 7667, 3235, 5128, 2123, 7763, 7971, 5422, 3319, 5160, 5679, 3220, 4796, 5970, 3679, 3571, 2521, 6088, 2568, 8141, 7153, 5794, 7235, 9396, 5300, 7467, 4171, 3800, 2291, 1577, 7960, 6376, 3382, 2301, 3069, 5428, 4945, 9310, 4107, 4948, 4470, 8660, 2711, 7290, 2377, 1603, 7600, 1607, 6014, 7812, 8846, 2250, 5741, 7930, 7275, 7480, 7303, 8664, 1785, 6857, 4836, 2655, 7775, 4005, 4169, 4354, 6946, 5338, 7893, 1648, 2158, 7859, 4543, 6354, 2405, 8652, 4959, 6121, 1391, 4251, 9507, 7497, 4610, 3694, 5263, 5064, 4138, 4000, 4219, 7549, 2594, 9077, 6853, 2278, 1077, 5626, 6116, 9622, 5035, 4589, 2109, 9844, 1882, 2527, 1289, 8592, 8809, 9604, 3333, 5657, 3470, 8969, 2688, 7301, 9917, 4229, 6441, 9304, 5083, 5467, 5543, 9771, 2384, 1910, 6908, 2471, 4583, 5360, 3807, 8199, 7880, 7546, 6605, 7588, 6781, 8752, 6802, 7433, 7868, 9750, 6280, 1709, 2511, 2453, 6235, 4548, 2208, 1971, 1043, 4408, 4660, 4530, 9005, 9213, 7424, 6199, 7661, 2481, 3003, 4730, 6362, 3623, 3118, 2344, 8439, 2432, 3027, 8713, 2311, 8650, 4175, 1558, 6417, 2949, 3296, 1722, 5887, 8161, 7943, 7306, 4940, 7721, 1236, 6741, 9299, 9544, 7874, 9460, 2685, 3188, 9333, 8037, 8945, 6883, 7034, 4624, 8241, 1544, 1154, 7554, 8477, 1974, 7585, 3472, 8821, 2330, 9447, 7417, 4302, 4125, 9662, 7818, 8586, 1055, 1649, 7319, 5434, 8407, 3096, 6829, 4480, 6597, 4552, 6100, 1675, 2064, 5165, 7267, 3518, 9053, 7269, 1471, 6142, 5147, 1252, 8107, 1175, 3659, 7565, 7898, 4684, 2314, 3572, 6446, 2201, 5845, 9691, 5533, 1358, 5561, 1767, 9754, 2827, 7817, 7903, 6918, 5603, 9168, 7014, 5937, 4495, 9370, 2414, 9725, 9745, 7256, 3574, 1587, 1460, 7628, 1181, 7471, 8385, 8409, 4721, 3468, 9752, 6005, 6263, 9721, 6591, 3935, 2001, 2543, 7300, 3580, 1883, 1237, 4476, 2122, 9055, 2753, 5178, 7857, 2185, 5271, 7206, 8255, 4180, 5808, 9258, 4643, 4453, 2547, 7511, 6903, 9130, 2138, 1586, 1070, 1605, 4876, 3323, 7329, 8948, 9688, 5738, 9919, 2837, 5608, 4681, 4742, 1361, 4831, 7621, 9231, 6214, 7965, 1435, 8404, 1672, 2120, 9171, 4296, 1640, 9185, 7096, 3863, 2626, 6949, 9047, 6663, 6668, 7795, 8654, 6279, 2307, 2831, 2847, 8998, 9270, 9516, 7001, 7638, 4525, 3768, 1663, 6029, 6210, 2447, 8763, 3289, 1128, 6790, 5403, 9731, 6275, 4407, 3578, 1317, 4568, 7410, 9107, 1833, 3789, 4808, 7441, 2816, 6480, 8014, 5919, 1469, 9886, 8738, 9918, 2612, 1213, 2153, 6699, 8127, 5732, 5181, 2822, 4289, 1299, 8813, 2604, 1164, 9800, 8234, 9975, 7006, 2767, 8925, 7132, 5475, 5528, 7802, 2530, 5436, 6420, 9340, 5556, 3915, 2683, 4269, 5578, 7790, 4905, 6482, 8406, 4719, 2092, 3286, 2555, 2735, 5104, 7798, 4729, 6329, 7990, 8299, 3170, 2226, 6112, 7789, 3353, 1278, 2707, 5659, 8978, 1298, 7979, 8307, 1862, 8125, 4855, 4991, 9224, 3570, 9697, 6248, 7828, 1385, 5826, 7759, 5777, 9225, 5572, 2168, 8202, 9506, 1102, 1423, 4890, 4118, 2417, 8170, 5448, 3209, 5731, 3325, 5495, 9123, 5247, 6739, 7715, 7477, 9161, 8445, 3762, 7167, 3330, 9619, 8300, 5666, 6544, 9970, 8226, 3247, 6807, 8394, 1623, 6763, 1291, 1405, 8035, 2197, 1412, 1898, 7292, 1827, 9926, 8639, 6977, 3140, 7494, 1968, 6254, 4526, 3513, 8693, 5562, 2258, 6810, 8559, 4383, 4123, 7643, 4265, 2716, 4972, 6138, 4174, 3855, 4679, 2174, 9842, 3295, 8635, 8822, 8180, 1601, 6128, 8896, 3317, 7492, 5613, 5400, 6970, 9853, 1146, 5372, 6238, 2441, 2132, 7324, 9528, 2679, 2240, 4566, 2430, 1519, 9135, 9251, 7640, 1918, 2888, 7046, 2857, 2036, 7793, 8992, 1763, 9873, 8118, 7651, 5098, 5408, 7699, 7767, 6060, 5114, 6317, 9673, 1378, 1808, 1176, 6783, 9428, 9934, 3734, 5476, 6951, 4821, 9900, 5911, 1885, 2435, 1865, 4019, 4493, 6306, 7076, 5606, 2431, 7630, 4223, 6133, 8922, 4042, 3655, 2326, 4595, 8615, 6766, 6695, 4017, 4612, 7761, 3487, 4188, 9302, 9368, 8977, 5026, 7490, 8443, 1347, 9149, 2486, 1001, 3186, 8771, 3454, 8517, 9874, 8789, 4422, 3735, 8506, 5275, 7500, 3225, 2825, 4728, 2703, 9717, 5760, 8155, 2680, 8166, 3480, 6372, 9518, 7458, 8285, 8175, 7015, 8824, 6746, 6161, 9411, 7296, 6416, 2811, 5474, 4210, 4989, 6057, 8462, 8941, 1872, 5652, 3639, 2199, 7469, 9235, 2357, 4859, 1245, 4908, 7925, 5223, 7022, 1646, 7919, 5051, 8279, 1777, 2248, 6213, 3792, 4582, 4064, 7563, 5644, 3368, 3847, 2719, 2126, 5014, 5517, 3047, 2508, 4142, 8940, 7351, 2361, 7762, 6331, 8433, 8811, 9099, 5683, 6339, 4879, 6006, 1890, 9116, 8731, 3783, 4134, 5669, 1325, 9194, 5693, 3912, 5868, 1449, 9966, 1352, 2644, 3101, 6895, 4985, 1502, 6369, 2172, 6784, 8768, 4377, 9138, 4935, 7180, 8957, 9198, 6093, 3080, 8168, 6499, 8755, 3918, 9508, 8449, 1583, 8080, 5633, 9573, 3575, 9679, 7646, 1189, 8860, 5961, 5525, 7604, 7203, 9712, 5582, 5593, 9101, 3957, 2492, 7177, 7025, 5637, 4562, 1140, 8287, 8458, 7100, 3272, 4358, 3358, 4743, 2660, 1897, 4261, 2026, 5824, 1315, 9468, 1790, 6395, 3529, 6042, 4412, 7673, 3907, 5945, 5753, 7227, 4182, 2723, 5305, 4547, 9414, 8724, 8221, 7591, 4421, 6502, 8160, 6261, 4373, 3326, 5353, 8111, 4518, 9483, 5396, 5792, 1228, 2424, 3097, 1093, 2385, 5298, 6391, 6012, 9058, 3778, 7434, 2332, 3531, 2282, 8452, 6765, 6311, 6855, 1300, 6103, 3340, 6384, 9163, 3040, 4026, 7470, 4379, 6450, 9125, 5361, 3072, 6114, 8081, 1415, 4150, 7186, 3048, 9230, 7787, 8144, 4769, 5228, 7843, 9775, 4080, 8283, 8370, 3758, 4238, 9431, 1908, 8829, 1748, 9730, 9928, 8827, 4104, 7092, 9344, 1196, 7666, 2799, 6969, 1562, 7383, 8959, 1286, 2921, 5478, 1708, 1731, 6106, 6612, 7330, 8968, 9110, 5853, 3328, 9532, 1059, 3579, 5100, 6523, 4847, 3609, 8849, 3903, 4446, 9142, 3104, 1370, 7611, 4410, 7074, 8905, 8626, 5917, 4228, 5983, 9027, 4969, 9880, 3547, 3954, 9427, 2906, 6036, 6719, 6043, 8337, 8193, 4968, 5276, 1356, 8418, 9869, 4577, 8758, 1088, 3699, 9044, 3449, 4173, 2782, 4918, 6426, 2956, 1795, 1362, 2103, 7004, 9052, 1863, 2937, 9332, 9681, 2387, 2245, 5358, 1806, 4447, 5929, 3374, 4549, 6477, 9211, 2483, 4851, 1439, 9401, 4397, 9732, 3638, 4561, 7163, 4429, 7174, 5069, 1319, 3927, 3039, 4980, 3533, 3087, 7864, 2550, 3240, 9983, 5643, 9999, 5697, 9625, 6705, 4516, 9943, 9511, 9937, 6698, 4363, 8851, 3615, 6038, 8338, 4883, 9061, 3151, 5258, 2380, 4294, 1108, 4741, 5383, 8656, 7942, 7909, 5956, 9820, 1834, 5281, 9672, 8803, 7086, 3025, 4648, 4203, 4081, 7891, 4955, 8099, 2450, 3625, 8873, 3309, 9454, 1891, 9316, 9716, 7140, 6594, 8766, 9746, 7367, 5712, 6623, 7487, 9337, 6027, 5231, 2184, 9707, 7786, 7456, 7414, 3541, 9579, 5557, 1074, 6788, 9659, 5568, 3823, 4416, 5872, 6577, 7354, 1951, 4882, 8447, 6642, 9703, 8989, 3303, 7406, 4333, 1052, 5834, 7464, 9985, 5951, 9626, 3592, 4076, 4670, 9708, 1893, 4783, 4083, 9690, 5049, 4788, 5745, 2790, 2833, 9572, 8858, 5173, 8637, 2102, 5180, 2448, 2283, 6026, 7446, 3797, 5520, 2611, 9541, 6657, 8077, 4009, 1990, 9733, 6389, 8646, 7785, 4394, 4295, 6916, 9847, 7010, 7270, 8493, 9603, 4490, 1556, 5470, 5002, 7776, 8341, 2316, 7869, 8499, 8002, 6819, 2260, 6715, 5931, 2150, 3916, 5411, 4176, 5751, 8159, 4824, 5309, 9176, 3511, 4195, 3654, 3448, 6231, 6901, 6755, 6337, 7220, 8427, 8601, 6185, 4896, 1697, 4667, 2979, 8417, 5866, 5438, 5590, 5589, 6364, 2060, 3537, 5673, 2505, 5805, 7097, 9341, 7703, 4666, 1755, 8266, 4161, 9839, 7504, 1780, 5041, 4445, 1422, 4202, 2634, 8653, 3568, 5381, 1619, 8815, 1321, 4315, 9599, 8273, 1911, 3688, 3937, 2534, 8314, 5389, 7626, 8185, 3740, 4784, 9533, 6966, 4709, 6486, 2701, 3341, 8816, 2730, 3798, 3016, 6421, 8570, 9553, 6430, 1520, 7888, 3483, 3816, 3227, 8845, 7769, 5278, 2637, 6646, 7007, 5817, 7734, 1936, 4590, 5560, 7672, 6861, 3736, 6649, 8263, 4906, 8807, 3742, 9159, 1267, 3233, 4308, 6671, 5781, 8564, 1680, 8240, 4102, 3395, 2722, 6985, 3154, 7405, 8669, 7252, 2018, 7055, 7536, 2455, 9373, 7323, 2085, 6930, 8339, 8351, 1092, 5610, 6481, 7117, 7134, 8850, 9318, 6186, 8356, 9315, 1681, 5957, 5433, 6768, 6546, 8156, 6493, 7101, 4475, 9756, 4653, 4252, 9836, 4827, 3219, 1906, 1274, 2912, 4258, 5132, 1904, 2155, 1760, 5054, 9591, 2560, 8609, 3505, 8431, 2606, 2066, 8023, 9106, 6827, 6159, 5473, 9276, 6427, 8091, 6469, 6309, 2643, 2277, 6859, 2041, 7712, 1470, 1063, 9834, 7207, 2889, 8286, 6163, 4310, 8491, 6092, 8291, 5464, 1626, 3160, 4688, 6471, 5721, 3583, 9770, 4794, 6948, 3067, 5879, 7371, 9686, 3820, 4600, 9248, 4758, 9156, 6215, 8340, 8070, 7158, 6401, 4432, 6919, 7415, 9441, 8020, 2004, 4351, 4585, 9059, 5548, 8246, 4536, 5392, 8733, 4066, 7287, 8701, 3600, 5749, 7814, 1363, 6803, 6513, 5369, 4124, 7461, 5769, 9098, 2839, 2262, 1147, 7090, 6052, 7189, 2426, 3702, 2288, 7320, 5765, 9768, 6178, 8918, 8108, 4148, 8852, 6570, 3121, 6408, 8436, 5460, 9840, 4873, 1171, 1588, 4555, 4283, 5947, 5616, 7866, 6962, 3938, 2849, 2393, 4278, 3976, 9178, 9279, 4211, 1721, 4911, 5304, 2896, 8798, 3284, 7509, 5280, 5130, 1674, 5729, 2280, 6817, 6102, 2678, 5437, 5904, 5843, 3149, 5880, 6135, 4678, 4300, 9465, 8353, 8105, 8645, 8029, 3458, 4909, 4380, 7830, 7483, 3493, 1336, 9519, 3248, 4097, 1392, 5809, 8355, 1585, 9209, 8830, 4153, 9490, 5040, 3787, 1210, 5092, 2522, 4166, 6879, 7274, 4284, 9931, 5515, 5452, 3430, 5220, 8886, 7709, 3969, 5767, 6503, 4494, 8115, 7595, 3670, 1457, 4852, 2295, 5265, 3951, 2796, 1713, 4840, 2259, 8129, 5376, 1669, 8098, 9254, 9678, 1632, 6607, 7973, 9831, 1973, 3189, 4706, 7580, 4239, 7080, 6640, 8734, 5927, 6292, 3919, 5695, 9450, 9560, 8484, 5112, 6678, 6863, 2910, 4155, 5727, 6368, 1417, 3462, 5491, 6757, 2411, 6924, 1840, 2645, 6737, 8350, 6688, 4634, 4121, 9482, 5198, 6432, 6301, 9461, 2237, 4441, 8496, 6087, 2115, 9723, 1206, 7172, 6777, 4588, 1198, 3386, 2474, 9282, 2884, 2832, 2146, 3437, 4052, 5916, 4767, 1462, 7540, 3281, 9247, 3148, 9780, 8415, 8381, 6021, 8371, 2955, 7183, 4196, 1694, 8383, 3263, 8200, 8598, 3752, 4253, 7916, 8902, 2713, 1488, 6624, 3011, 6472, 3810, 5526, 4938, 2779, 2473, 5110, 7560, 7352, 3952, 7996, 9888, 1919, 1331, 9054, 3720, 2512, 2379, 3761, 1638, 9402, 4898, 7196, 7532, 2539, 5312, 2279, 4625, 8757, 7165, 3909, 6448, 9429, 5488, 2502, 2974, 8334, 2981, 6701, 3508, 1310, 3013, 1239, 9352, 1950, 7947, 6787, 7327, 1056, 3893, 9968, 9160, 5755, 6986, 4800, 2145, 9070, 1339, 2272, 6514, 1401, 5444, 2818, 4415, 6487, 7197, 5835, 6813, 1433, 1841, 2893, 6390, 5527, 3836, 8274, 7128, 4994, 2677, 5886, 4967, 5574, 3024, 6732, 1838, 4287, 4650, 5764, 9930, 7307, 7581, 8904, 6080, 7066, 3074, 1589, 2876, 4187, 9363, 2813, 3837, 1946, 8086, 6833, 6812, 1884, 4286, 9261, 5902, 3402, 4508, 1509, 8947, 5726, 1216, 5479, 4385, 9089, 3565, 1125, 1327, 7360, 8519, 7632, 3959, 6067, 9186, 7281, 5246, 7950, 3514, 1571, 6359, 7476, 5819, 3165, 2601, 4895, 1311, 4013, 3187, 6386, 2031, 3258, 2130, 2047, 9090, 2528, 7535, 1828, 3238, 1621, 9815, 1696, 8548, 1593, 5775, 8927, 1768, 4764, 2319, 4541, 7214, 5583, 1597, 3453, 2792, 5387, 8135, 1222, 9080, 1871, 9451, 2196, 8868, 1250, 4483, 5750, 2700, 3633, 5061, 2686, 5272, 9040, 9480, 3681, 1094, 7907, 6553, 7831, 5261, 9895, 2375, 3874, 3576, 3419, 4740, 3352, 7991, 5136, 2807, 7317, 1880, 1065, 8157, 5084, 2343, 7924, 7185, 9764, 1870, 4871, 2244, 5311, 3116, 3443, 9456, 4828, 9471, 4523, 9638, 3089, 3685, 3677, 2238, 6355, 7772, 5415, 2544, 1899, 2757, 4626, 2023, 9857, 8819, 7050, 5509, 1915, 8536, 4463, 8227, 5062, 3590, 7523, 8908, 3367, 5366, 1664, 9399, 1005, 7451, 9912, 5419, 8058, 2362, 3405, 9153, 8981, 4862, 8008, 5229, 2372, 1592, 3270, 4448, 4822, 9854, 4817, 9809, 9806, 9426, 8460, 1852, 3077, 6801, 7435, 1912, 9366, 6850, 8859, 3034, 1629, 3310, 4127, 5036, 9817, 2014, 9804, 7150, 1992, 8571, 7387, 2930, 5920, 6816, 5689, 2267, 1665, 5391, 1728, 3192, 6676, 7262, 8722, 5955, 9713, 7047, 6084, 9580, 7897, 1724, 8773, 2177, 6195, 7272, 2003, 9390, 1118, 2180, 6614, 4189, 8100, 4442, 1849, 8074, 2415, 7995, 5386, 8464, 8123, 6459, 1887, 7334, 2192, 6934, 1173, 8178, 6697, 8028, 2900, 6045, 3993, 3896, 7040, 6549, 2194, 2207, 2861, 1014, 2537, 2771, 7190, 3293, 2588, 2765, 3133, 4665, 8311, 2826, 1894, 4089, 5248, 9969, 5172, 1624, 3658, 7542, 6560, 2985, 7171, 8627, 3207, 3481, 8090, 6506, 9606, 5048, 9938, 3593, 4250, 6604, 4987, 5188, 5710, 3838, 6847, 4117, 8673, 3650, 1127, 2309, 7933, 4462, 6485, 3390, 5011, 5552, 4512, 5933, 7962, 4910, 1458, 3766, 3185, 9487, 7068, 6795, 9078, 2401, 5736, 6143, 7107, 4573, 3425, 6320, 7815, 6574, 2176, 7936, 1100, 3923, 1517, 2720, 4888, 1799, 1704, 9666, 1256, 6524, 3019, 1309, 5989, 5672, 8271, 5639, 9569, 3627, 4332, 7783, 6406, 8181, 3055, 7934, 2886, 1962, 6048, 3731, 6286, 3791, 6745, 1451, 6673, 5708, 4996, 9175, 6647, 9013, 5811, 6189, 3799, 4492, 4977, 8265, 4673, 2600, 2577, 2480, 6234, 3997, 4646, 4204, 8681, 7804, 7333, 5052, 9627, 8836, 2266, 8204, 4130, 7398, 5540, 9868, 1188, 1856, 2422, 3221, 4954, 9512, 8967, 4850, 9706, 7033, 7422, 4199, 3218, 6551, 3603, 5032, 5554, 8988, 7363, 1533, 3103, 4382, 7009, 8310, 6260, 6815, 3856, 5949, 4059, 1091, 8191, 8382, 3210, 2191, 2054, 2834, 8539, 1771, 3205, 4699, 5522, 6049, 7528, 2764, 3320, 9108, 7824, 6940, 5748, 6444, 5318, 1103, 8480, 8165, 4115, 1162, 9876, 4656, 1688, 1473, 8667, 6501, 9081, 2170, 3844, 1932, 6467, 5365, 7032, 2620, 3803, 9348, 3953, 5599, 7233, 9418, 9545, 3145, 8360, 1394, 3894, 9982, 2770, 1194, 1452, 6923, 5044, 8188, 5924, 8215, 8479, 5692, 1342, 1812, 4521, 1999, 7610, 3440, 9669, 7871, 3991, 3769, 4864, 5283, 6868, 8926, 6596, 9011, 8500, 4158, 8018, 6115, 2829, 6717, 8390, 8122, 6694, 7425, 8805, 7493, 3093, 3649, 2607, 3870, 4528, 9346, 8516, 8674, 5612, 3451, 1937, 4230, 1948, 4318, 1263, 4668, 9030, 8293, 9265, 8391, 3431, 5038, 7289, 3631, 5587, 3612, 7228, 2772, 4652, 4620, 6282, 3158, 3904, 3083, 9436, 1061, 1523, 7813, 4498, 6388, 1066, 3987, 3484, 5709, 1386, 9464, 7201, 8437, 4756, 5245, 1559, 9744, 6648, 7937, 9145, 8767, 4368, 1507, 9535, 2750, 8533, 6004, 8507, 9383, 6316, 9698, 1835, 4839, 9167, 4272, 8489, 2050, 4178, 5133, 6618, 9433, 6586, 1594, 8794, 7085, 8459, 9269, 9049, 9170, 8132, 4806, 3385, 7955, 9825, 5634, 5135, 7041, 1820, 5174, 3895, 8380, 1984, 4952, 9718, 5115, 6683, 3203, 1135, 3346, 7266, 7394, 5977, 8096, 1673, 6852, 6250, 2241, 7634, 7161, 2519, 1359, 8557, 4424, 4240, 7706, 9303, 1753, 4947, 6086, 8017, 6617, 4744, 3137, 5828, 9682, 2766, 3970, 8405, 5998, 3164, 3998, 4799, 7746, 9818, 4096, 8021, 1141, 2977, 3362, 4770, 4606, 5682, 4370, 5907, 3759, 5398, 1441, 5988, 9102, 9667, 8800, 1549, 6212, 3582, 8764, 8840, 2586, 7989, 8119, 5553, 9961, 2684, 3477, 1345, 3435, 7347, 7356, 8235, 7822, 1888, 1499, 6726, 9317, 1292, 3228, 2358, 8542, 6749, 3232, 8781, 9993, 6066, 9365, 7440, 5167, 6722, 4403, 6187, 3849, 2787, 6759, 9355, 7237, 6826, 1015, 5179, 8373, 3409, 3321, 2074, 4960, 6659, 6129, 3930, 1301, 9218, 5774, 1848, 6610, 8817, 2009, 6290, 4264, 1682, 2526, 6165, 9328, 8064, 9564, 1421, 9417, 3473, 4532, 5186, 6434, 5855, 8410, 5664, 4141, 6022, 4793, 4061, 6943, 5380, 9349, 7088, 1995, 5141, 8622, 9103, 1172, 1786, 6411, 8939, 6505, 4339, 3176, 4823, 7612, 1000, 5733, 7741, 1491, 9009, 6308, 7058, 2137, 3861, 1825, 3194, 2491, 3713, 1271, 3707, 7527, 1967, 8057, 3733, 2160, 3231, 1349, 6325, 9944, 2488, 2463, 4039, 7345, 5195, 7496, 3534, 3611, 2303, 2409, 4322, 8621, 7238, 9668, 2945, 2042, 6519, 5535, 6520, 7294, 5210, 6629, 8374, 2347, 3262, 4362, 1532, 1633, 4313, 3697, 8550, 3064, 9929, 1480, 9658, 6171, 4365, 6566, 6324, 7198, 7683, 9076, 3884, 1565, 3054, 9920, 6978, 7322, 7176, 4263, 4303, 4689, 4596, 6284, 6035, 5171, 8033, 5624, 9274, 5895, 1839, 8545, 4875, 1791, 3635, 8643, 7489, 3485, 1099, 1233, 3065, 6180, 8113, 3266, 7192, 1251, 2994, 5960, 7819, 5631, 1479, 5497, 1933, 4073, 9610, 3450, 3030, 4048, 6860, 3070, 6664, 6912, 9687, 4807, 2562, 1453, 9783, 6656, 9023, 9877, 4682, 4934, 1653, 6881, 6203, 4527, 6563, 9674, 1305, 2579, 5332, 1134, 6332, 7286, 9615, 9497, 8659, 2802, 1414, 9406, 8461, 2941, 2403, 6728, 3370, 4772, 7766, 6794, 4344, 8838, 3619, 6780, 3099, 2007, 5848, 7629, 7635, 3010, 5218, 1431, 9362, 2840, 3446, 1284, 4390, 6370, 5773, 2926, 6307, 1246, 7089, 6123, 9206, 3045, 2582, 5675, 9100, 4810, 5244, 3503, 7259, 8042, 5740, 2039, 9287, 1503, 4077, 2029, 9769, 5089, 2175, 1200, 1576, 2000, 8594, 4973, 6259, 2462, 6153, 9387, 7064, 7226, 3117, 5010, 6206, 5015, 2421, 4257, 9446, 7018, 2762, 4162, 1139, 2227, 1879, 7863, 8593, 1195, 6041, 3021, 8451, 2681, 8150, 2669, 7853, 1685, 6672, 7904, 7225, 9190, 8243};
    int array[10] = {5, 9, 6, 3, 4, 2, 7, 10, 8, 1};
    DisplayArray(array, 10);
    QuickSort(array, 0, 10 - 1);
    DisplayArray(array, 10);
}