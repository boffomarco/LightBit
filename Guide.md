# LightBit Sleep detection
We will use the materia offered at https://alpha.physionet.org/content/sleep-accel/1.0.0/ with License (for files):Open Data Commons Attribution License v1.0

# Set Up to compute the detection:
## Create Virtual Environment on Python 3
python3 -m virtualenv sleep_detection
## Activate Virtual Environment
source sleep_detection/bin/activate
## Install requirements
pip install numpy==1.18.4

pip install -r sleep_classifiers/requirements.txt

# Run the experiment
## Download experimental data from [here](https://alpha.physionet.org/static/published-projects/sleep-accel/motion-and-heart-rate-from-a-wrist-worn-wearable-and-labeled-sleep-from-polysomnography-1.0.0.zip)
## Move data inside the relative folders inside sleep_classifiers/data
## Set the moved data also inside subjects_as_ints list on sleep_classifiers/source/analysis/subject_builder.py
## Run the experiment inside the virtual environment with the following commands:

python3 sleep_classifiers/source/preprocessing/preprocessing_runner.py

python3 sleep_classifiers/source/analysis/analysis_runner.py

## MATLAB for MESA dataset usage (not used)
### Edit sleep_classifiers/source/constants with Matlab Path 
### Install Signal Processing ToolBox on MatLab 

# References
## Resources
Walch, O. (2019). Motion and heart rate from a wrist-worn wearable and labeled sleep from polysomnography (version 1.0.0). PhysioNet. https://doi.org/10.13026/hmhs-py35.
## Publication
Olivia Walch, Yitong Huang, Daniel Forger, Cathy Goldstein, Sleep stage prediction with raw acceleration and photoplethysmography heart rate data derived from a consumer wearable device, Sleep
## PhysioNet
Goldberger, A., Amaral, L., Glass, L., Hausdorff, J., Ivanov, P. C., Mark, R., ... & Stanley, H. E. (2000). PhysioBank, PhysioToolkit, and PhysioNet: Components of a new research resource for complex physiologic signals. Circulation [Online]. 101 (23), pp. e215–e220.