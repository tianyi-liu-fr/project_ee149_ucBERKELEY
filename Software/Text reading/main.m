%%
clc 
clear all
close all


 %%
while true
    prompt = " 0: Read | 1: turn off ";
    x = input(prompt)
    if(x == false)
        % analyze of the text
        businessCard = imread('https://drive.google.com/uc?export=view&id=1urovcbte-OW4xxzmRcqCOQzjM0dYnVZV', 'png');
        %businessCard = imread("Test.png");
        ocrResults     = ocr(businessCard);
        recognizedText = ocrResults.Text;   
        L= length(recognizedText);
        if(L <= 3)
            disp("No tengo texto")
        end
        if( L > 3)
           %figure;
            %imshow(businessCard);
            %text(600,150,recognizedText,"BackgroundColor",[1 1 1]);
            %userPrompt = 'What do you want the computer to say?';
            %titleBar = 'Text to Speech';
            defaultString = recognizedText;
    %       caUserInput = inputdlg(userPrompt, titleBar, 1, {defaultString});
    %       caUserInput = char(caUserInput); % Convert from cell to string.
    %       NET.addAssembly('System.Speech');
            %obj = System.Speech.Synthesis.SpeechSynthesizer;
            obj.Volume = 100;
            %speak(obj, caUserInput);
            tts(ocrResults.Text);
        end


    end
    
    % mode sleep 
    if(x == true)
        disp("end !")
        break;
    end
    
end

%%
% k = 0;
% while true
%     k = k+1;
%     disp(k);
%     if k == 10;
%         break;
%     end
% 
% end
% 



