# The-Beacon-Formula-Calculator

This is a calculator used to compute the area of a beacon layer and the sum of the beacon layers' areas using the beacon formulas. The user must write the needed inputs which are the layer number height, the length, and the width, the maximum layer number height, and the deducted beacon blocks. As the formulas are written inside the calculator when it is run, there are certain inputs that should be avoided.

Inputs the causes error:
1. For h as the layer number height, h cannot be less than 0.
2. For L as the length, L cannot be less than or equal to 0.
3. For W as the width, W cannot be less than or equal to 0.
4. For m as the maximum layer number height, m cannot be less than or equal to 0.
5. For beta as the deducted area of the beacon blocks, beta cannot be greater than or equal to the length multiplied by the width (L*W).

This calcuator is programmed with C, and C++.
(PYTHON IS COMING SOON).
