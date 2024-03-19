# Define the source and destination paths
source_config="."
destination_config="/etc/paradox"

# Create the destination directory if it doesn't exist
if sudo mkdir -p "$destination_config"; then
    :
else
    echo "Error: Failed to create destination directory $destination_config"
    exit 1
fi

# Copy the default config.json to the destination directory
if sudo cp "$source_config/conf.json" "$destination_config/"; then
    :
else
    echo "Error: Failed to generate config file."
    exit 1
fi

# Set appropriate permissions for the copied file
if sudo chmod 644 "$destination_config/conf.json"; then
    :
else
    echo "Error: Failed to set permissions for config file."
    exit 1
fi

echo "Generated default config '$destination_config/conf.json'"
