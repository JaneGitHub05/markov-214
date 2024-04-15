% A visualizer for unfettered markov process given a certain word for a
% preestablished matrix

% input: 
%   probability matrix "wordMat" (given one word)
%   vector "wordVec" IDing specific word
%   numIter = number of steps to take
%   totalWords = number of unique words in the matrix



function lyrics = Bumblebee(wordMat, beginVec, numIter, totalWords, reset)
    i = 0;
    addWord = false;
    theta = linspace(1, 2*pi, totalWords);
    x = totalWords*0.2*cos(theta);
    y = totalWords*0.2*sin(theta);
    lyrics = zeros(1, numIter);
    figure();
    plot(x, y,'.','MarkerSize',50,'Color', "red");
    hold on;
    text(x, y, totalWords);
    currIndex = find(beginVec==1);
    currProb = beginVec;
    
    while i < numIter
        wait time (2 second);
        %find next word and also recalc matrix and vector for next word
        prevIndex = currIndex;
        [currProb, currIndex] = nextWord(wordMat, currProb); % have this take vec and return vec
        posPrev = [x(prevIndex) y(prevIndex)];
        posCurr = [x(currIndex) y(currIndex)];
        posDiff = posCurr-posPrev;
        if reset
            currProb = max(currProb) == currProb;
        end
        quiver(posPrev(1), posPrev(2), posDiff(1), posDiff(2), 0);
        hold on;
        lyrics(i) = totalWords(max(currProb));
        i = i+1;

    end

        


