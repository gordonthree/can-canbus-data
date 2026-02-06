# Common CAN bus include files used across multiple projects

Instructions for the python script to transform messages.csv into canbus_msg.h
Run this outside of VSCode

make sure the two csv files are in the same directory

```powershell
# The 'venv' at the end is the name of the folder it will create
python -m venv venv

# Activate the virtual environment
.\venv\Scripts\Activate.ps1

# Install dependencies
pip install pandas

# Run the script
python format_msgs.py

# Deactivate the virtual environment    
deactivate
```
