clc; clear; close all;

while true

    % Wait for user input (will change to physical button)
    prompt = "Read picture? (Y/N): ";
    in = input(prompt, "s");
    
    if((in == 'Y') || (in == 'y'))

        % Read image from Google Drive
        driveID = '1urovcbte-OW4xxzmRcqCOQzjM0dYnVZV';
        img = imread(['https://drive.google.com/uc?export=view&id=', ...
            num2str(driveID)], 'png');

        % Extract text
        ocrResults = ocr(img);

        % Save recognized text
        recogTxt = ocrResults.Text;

        % Detect if there's text and display it
        if(length(recogTxt) <= 3)
            recogTxt = 'No text';
            disp('Recognized text:');
            disp(recogTxt);    
        else
            disp('Recognized text:');
            disp(recogTxt);
        end

        % Show image taken for debugging
        figure(1);
        imshow(img);
    
    % Break while loop when requested
    elseif((in == 'N') || (in == 'n'))
        break
    end
    
end