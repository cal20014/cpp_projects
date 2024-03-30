import os

def rename_files(directory):
    for filename in os.listdir(directory):
        if "Lab12" in filename:
            new_filename = filename.replace("Lab12", "artillerySimulator")
            os.rename(os.path.join(directory, filename), os.path.join(directory, new_filename))

# Use the current directory path
rename_files('C:\\Users\\kg7sh\\OneDrive\\Documents\\kg7shw_dev\\personalProjects\\cpp_projects\\M777HowitzerArtillerySimulator')