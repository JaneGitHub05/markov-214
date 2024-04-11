% A visualizer for unfettered markov process given a certain word for a
% preestablished matrix

% input: 
%   probability matrix "wordMat" (given one word)
%   vector "wordVec" IDing specific word
%   numIter = number of steps to take
%   totalWords = number of unique words in the matrix



function process = Bumblebee(wordMat, wordVec, numIter, totalWords)
    i = 0;
    Words = wordVec;
    addWord = false;
    theta = linspace(1, 2*pi, totalWords);
    x = totalWords*0.2*cos(theta);
    y = totalWords*0.2*sin(theta);
    plot(x, y,'.','MarkerSize',5,'Color', [194 197 204]);
    while i < numIter
        %find next word and also recalc matrix and vector for next word
        [currProb, currIndex] = nextWord(wordMat, wordVec);
        


