(function ($) {

    $(document).ready(function() {
        $('.bv-form').bootstrapValidator({
            message: 'This value is not valid',
            feedbackIcons: {
                valid: 'glyphicon glyphicon-ok',
                invalid: 'glyphicon glyphicon-remove',
                validating: 'glyphicon glyphicon-refresh'
            },
            fields: {
                title: {
                    message: 'The item is not valid',
                    validators: {
                        notEmpty: {
                            message: 'Please enter an item.'
                        },
                        stringLength: {
                            min: 3,
                            max: 255,
                            message: 'Please enter an item.'
                        },
                    }
                },
                type: {
                    validators: {
                        notEmpty: {
                            message: 'Select a type.'
                        },
                    }
                },
                mail: {
                    validators: {
                        notEmpty: {
                            message: 'Please enter your email address.'
                        },
                        emailAddress: {
                            message: 'Invalid email address.'
                        }
                    }
                },
                name: {
                    validators: {
                        notEmpty: {
                            message: 'Please enter your email address.'
                        },
                        emailAddress: {
                            message: 'Invalid email address.'
                        }
                    }
                },
                pass: {
                    validators: {
                        notEmpty: {
                            message: 'Please enter your password.'
                        },
                    }
                }
            }
        });
    });

}(jQuery));

