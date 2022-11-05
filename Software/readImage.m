
%%
clc 
clear all
close all

%%

businessCard   = imread("Test.png");
ocrResults     = ocr(businessCard);
recognizedText = ocrResults.Text;    
figure;
imshow(businessCard);
text(600,150,recognizedText,"BackgroundColor",[1 1 1]);

%%

userPrompt = 'What do you want the computer to say?';
titleBar = 'Text to Speech';
defaultString = recognizedText;
caUserInput = inputdlg(userPrompt, titleBar, 1, {defaultString});

caUserInput = char(caUserInput); % Convert from cell to string.
NET.addAssembly('System.Speech');
obj = System.Speech.Synthesis.SpeechSynthesizer;
obj.Volume = 60;
Speak(obj, caUserInput);

%%

tts(ocrResults.Text);




